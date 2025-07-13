#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <chrono>
#include <iostream>
#include <algorithm>


using namespace std;

//----to observe multithreading performance

#define ARRAY_SIZE 10000 //value till which summed up
#define n 2 //no of threads to be created

vector<int> arr(ARRAY_SIZE);

void generateRandomArray(){
    srand(time(0));
    for (int i=0; i<ARRAY_SIZE; i++){
        arr[i]=rand()%100000+1;
    }
}

struct threadArgs{
    int id; //to identify thread
    int start; //start of range
    int end; //end of range
};

void* sortArrayMultiThreads(void*arg){
    threadArgs* data=(threadArgs*)arg;
    sort(arr.begin()+data->start, arr.begin()+data->end);
    pthread_exit(nullptr);
}

void sortArraySingleThread(){
    sort(arr.begin(), arr.end());
}

void mergeSortedArrays(){
    int arrayPartitionValues=ARRAY_SIZE/n;
    for (int i=0; i<n; i++){
        inplace_merge(arr.begin(), arr.begin()+i*arrayPartitionValues, arr.begin()+((i+1)*arrayPartitionValues));
    }
}

//----to view multithread performance

int main(){
    vector<pthread_t> thread(n);
    generateRandomArray();
    int arrayPartitionValues=ARRAY_SIZE/n;
    auto startTime=chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++){
        threadArgs* args=new threadArgs;
        args->id=i;
        args->start=i*arrayPartitionValues;
        args->end=(i==n-1)?ARRAY_SIZE:(i+1)*arrayPartitionValues;

        pthread_create(&thread[i], nullptr, sortArrayMultiThreads, args);
    }

    for (int i=0; i<n; i++){
        pthread_join(thread[i], nullptr);
    }

    mergeSortedArrays();

    auto endTime=chrono::high_resolution_clock::now();
    chrono::duration<double>elapsedTime=endTime-startTime;
    cout<<"Multithread sort is achieved in time: "<<elapsedTime.count()<<" using "<<n<<" threads"<<endl;
    return 0;
}

//----to observe sequential performance
/*
int main(){
    generateRandomArray();
    auto startTime=chrono::high_resolution_clock::now();
    sortArraySingleThread();
    auto endTime=chrono::high_resolution_clock::now();
    chrono::duration<double>elapsedTime=endTime-startTime;
    cout<<"Sequential sort is achieved in time: "<<elapsedTime.count()<<endl;
}
*/
/*
Modify value of n in line 10, to create desired number of threads
Comment out lines 49 to 74, and uncomment lines 78 to 85, to observe sequential performance and the reverse for multithread performance

to run the program:
1. open terminal
2. navigate to correct directory
3. use command "g++ Assgn4SrcQ1-ArnabMandal.cpp -o q2 -pthread"
4. use command "./q2"
*/