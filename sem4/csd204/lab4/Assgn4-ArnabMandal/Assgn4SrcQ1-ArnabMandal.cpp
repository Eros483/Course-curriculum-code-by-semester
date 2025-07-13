#include <unistd.h>
#include <pthread.h>
#include <vector>
#include <chrono>
#include <iostream>

//----to observe multithreading performance

#define MAX 1000000 //value till which summed up
#define n 18 //no of threads to be created

using namespace std;

long long partialSums[n];

struct threadArgs{
    int id; //to identify thread
    int start; //start of range
    int end; //end of range
};

void* sumInRange(void* arg){
    threadArgs* args=(threadArgs*)arg;
    long long partialSumThread=0;

    for (int i=args->start; i<=args->end; i++){
        partialSumThread+=i;
    }
    
    partialSums[args->id]=partialSumThread;
    delete args;
    return nullptr;
}

int main(){
    vector<pthread_t> thread(n);
    int rangeSizes=MAX/n;

    auto startTime=chrono::high_resolution_clock::now();
    for (int i=0; i<n; i++){
        threadArgs* args=new threadArgs;
        args->id=i;
        args->start=i*rangeSizes+1;
        args->end=(i==n-1)?MAX:(i+1)*rangeSizes;

        pthread_create(&thread[i], nullptr, sumInRange, args);
    }

    for (int i=0; i<n; i++){
        pthread_join(thread[i], nullptr);
    }

    long long totalSum=0;
    for (int i=0; i<n; i++){
        totalSum+=partialSums[i];
    }

    auto endTime=chrono::high_resolution_clock::now();
    chrono::duration<double>elapsedTime=endTime-startTime;

    cout<<"Total Sum: "<<totalSum<<" found in time: "<<elapsedTime.count()<<" seconds while using "<<n<<" threads."<<endl;

    return 0;
}

//----to observe sequential performance

/*int main(){
    long long sum=0;
    auto startTime=chrono::high_resolution_clock::now();
    for (int i=0; i<=MAX; i++){
        sum+=i;
    }
    auto endTime=chrono::high_resolution_clock::now();
    chrono::duration<double>elapsedTime=endTime-startTime;

    cout<<"Total Sum: "<<sum<<" found in time: "<<elapsedTime.count()<<" seconds while processing Sequentially"<<endl;
}*/

/*
Modify value of n in line 10, to create desired number of threads
Comment out lines 8 to 65, and uncomment lines 68 to 78, to observe sequential performance

to run the program:
1. open terminal
2. navigate to correct directory
3. use command "g++ Assgn4SrcQ1-ArnabMandal.cpp -o q1 -pthread"
4. use command "./q1"
*/