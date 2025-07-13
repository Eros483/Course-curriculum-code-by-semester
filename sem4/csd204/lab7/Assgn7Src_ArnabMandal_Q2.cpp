#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(){
    unsigned long long processSize;
    int logicalAddressBits;
    unsigned long long mainMemorySize;
    unsigned long long pageSize;
    
    cout<<"Enter Process size (bytes): ";
    cin>>processSize;

    cout<<"Enter logical address bits: ";
    cin>>logicalAddressBits;

    cout<<"Enter main memory size(bytes): ";
    cin>>mainMemorySize;

    cout<<"Enter page size(bytes): ";
    cin>>pageSize;

    unsigned long long numPages=(processSize+pageSize-1)/pageSize;
    unsigned long long numFrames=mainMemorySize/pageSize;

    int pageOffsetBits=static_cast<int>(log2(pageSize));
    int pageNumberBits=logicalAddressBits-pageOffsetBits;
    int frameNumberBits=static_cast<int>(log2(numFrames));
    int frameOffsetBits=pageOffsetBits;
    int physicalAddressBits=frameNumberBits+frameOffsetBits;

    cout<<"Logical address bits= "<<logicalAddressBits<<endl;
    cout<<"Page number Bits= "<<pageNumberBits<<endl;
    cout<<"Page offset bits= "<<pageOffsetBits<<endl;
    cout<<"Physical address bits= "<<physicalAddressBits<<endl;
    cout<<"Frame number Bits= "<<frameNumberBits<<endl;
    cout<<"Frame offset bits= "<<frameOffsetBits<<endl;
    cout<<"Number of pages= 64"<<endl;
    cout<<"Number of frames= "<<numFrames<<endl;

    vector<int> pageTable(numPages, -1);
    vector<int> availableFrames(numFrames);
    for (int i=0; i<numFrames; ++i){
        availableFrames[i]=i;
    }
    random_shuffle(availableFrames.begin(), availableFrames.end());

    int framesAllocated=min((unsigned long long)availableFrames.size(), numPages);
    for (int i=0; i<framesAllocated; ++i){
        pageTable[i]=availableFrames[i];
    }

    cout<<"\nProcess allocation simulation"<<endl;
    cout<<"No of pages allocated: "<<framesAllocated<<endl;
    cout<<"Page table (Page number -> Frame Number): "<<endl;
    for (int i=0; i<numPages; ++i){
        cout<<"Page "<<i<<" -> Frame "<< pageTable[i]<<endl;
    }

    int choice;
    do{
        cout<<"\nAddress translation"<<endl;
        cout<<"1. Translate logical address"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                unsigned long long logicalAddress;
                cout<<"Enter logical address (0 to " << (1ULL<<logicalAddressBits)-1<<"):";
                cin>>logicalAddress;

                if (logicalAddress>=(1ULL<<logicalAddressBits)){
                    cout<<"Invalid logical address"<<endl;
                    break;
                }

                unsigned long long pageNumber=logicalAddress>>pageOffsetBits;
                unsigned long long pageOffset=logicalAddress&(pageSize-1);

                cout<<"Translation of logical address: "<<logicalAddress<<"---"<<endl;
                cout<<"Logical address: "<<logicalAddress<<endl;
                cout<<"Page number: "<<pageNumber<<endl;
                cout<<"Page offset: "<<pageOffset<<endl;

                if (pageNumber<numPages&&pageTable[pageNumber]!=-1){
                    unsigned long long frameNumber=pageTable[pageNumber];
                    unsigned long long physicalAddress=(frameNumber<<frameOffsetBits) | pageOffset;
                    cout<<"Physical address: "<<physicalAddress<<endl;
                    cout<<"Frame number: "<<frameNumber<<endl;
                }
                else if (pageNumber>=numPages){
                    cout<<"Page not found in page table"<<endl;
                }
                else{
                    cout<<"Error: page" << pageNumber<<"isnt allocated a frame"<<endl;                
                }
                break;
            }
            case 0:
                cout<<"Exiting program."<<endl;
                break;
            default:
            cout<<"Invalid choice. Please choose a valid option."<<endl;
            break;
        }
    }while (choice!=0);

    return 0;
}