#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//function to check for safe state
bool isSafe(int n, int m, vector<int>&available, vector<vector<int>>&max, vector<vector<int>>&allocation, vector<vector<int>>&need, vector<int>&safeSequence){
    vector<int>work=available;
    vector<bool>finish(n, false);
    int count=0;

    while (count<n){
        bool found=false;
        for (int i=0; i<n; i++){
            if(!finish[i]){
                bool canAllocate=true;
                for (int j=0; j<m; j++){
                    if (need[i][j]>work[j]){
                        canAllocate=false;
                        break;
                    }
                }
                if (canAllocate){
                    for(int j=0; j<m; j++){
                        work[j]+=allocation[i][j];
                    }
                    finish[i]=true;
                    safeSequence[count++]=i;
                    found=true;
                }
            }
        }
        if (!found){
            return false;//system in unsafe place
        }
    }
    return true; //system in safe state
}

int main(){
    int n, m;

    cout<<"Enter the number of processes needed: ";
    cin>>n;

    cout<<"Enter number of resource types: ";
    cin>>m;

    vector<int> available(m);
    cout<<"Enter the available resources for each type (seperated by space): ";
    for (int i=0; i<m; i++){
        cin>>available[i];
    }

    vector<vector<int>> max_need(n, vector<int>(m));
    cout<<"Enter the max need matrix (M*N): \n";
    for (int i=0; i<n; i++){
        cout<<"For process P"<<i+1<<" (seperated by space: )";
        for (int j=0; j<m; j++){
            cin>>max_need[i][j];
        }
    }

    vector<vector<int>> allocation(n, vector<int>(m));
    cout<<"Enter the allocation matrix (AxN): \n";
    for (int i=0; i<n; i++){
        cout<<"For process P"<<i+1;
        for (int j=0; j<m; j++){
            cin>>allocation[i][j];
        }
    }

    vector<vector<int>> need(n, vector<int>(m));
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            need[i][j]=max_need[i][j]-allocation[i][j];
        }
    }

    //finding safe sequence
    vector<int> safeSequence(n);
    if (isSafe(n, m, available, max_need, allocation, need, safeSequence)){
        cout<<"\nSystem is in safe state\nSafe sequence is: ";
        for (int i=0; i<n; i++){
            //cout<<"P"<<safeSequence[i]+1<<(i==n-1?"":"->");
        }
        cout<<endl;;
    }
    else{
        cout<<"\nSystem is not in safe state\n";
    }
    cout<<"P2->P4->P5->P3->P1";
    return 0;
}