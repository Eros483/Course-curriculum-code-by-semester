#include <iostream>
#include <pthread.h>
#include <atomic>

using namespace std;

atomic<int> counter=0;

struct threadData{
    int i;
};

int numberOfThreads;

void*counterIncrement(void* args){
    threadData*thisThread=(threadData*)args;
    int threadID=thisThread->i;
    counter.fetch_add(1, memory_order_relaxed);

    delete thisThread;
    return nullptr;
}

int main(){
    cout<<"Enter value counter is to be incremented to: "<<endl;
    cin>>numberOfThreads;
    
    pthread_t threads[numberOfThreads];
    srand(time(0));
    for (int j=0; j<numberOfThreads; j++){
        threadData* data=new threadData;
        data->i=j;
        pthread_create(&threads[j], nullptr, counterIncrement, data);
    }

    for(int i=0; i<numberOfThreads; i++){
        pthread_join(threads[i], nullptr);
    }

    cout<<counter.load(memory_order_acquire)<<endl;
}

