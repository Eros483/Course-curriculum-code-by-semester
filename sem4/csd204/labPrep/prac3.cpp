#include <iostream>
#include <pthread.h>

#define n 5
#define arraySize 10

int targetArray[arraySize]={1, 2, 3, 4, 5, 6, 9, 2, 7, 10};

int target=7;

int targetLocation;
bool targetFound=0;

pthread_mutex_t mutex;

using namespace std;

struct threadData{
    int i;
    int start;
    int end;
};

void*targetSearch(void*args){
    threadData* targetThreadData=(threadData*)args;
    for (int i=targetThreadData->start; i<targetThreadData->end; i++){
        if (targetArray[i]==target){
            pthread_mutex_lock(&mutex);
            targetFound=1;
            targetLocation=i;
            pthread_mutex_unlock(&mutex);
        }
    }
    return nullptr;
}

int main(){
    pthread_t threads[n];

    for (int i=0; i<n; i++){
        threadData* thisThread=new threadData;
        thisThread->i=i;
        thisThread->start=i*arraySize/n;
        thisThread->end=(i==n-1)?arraySize:(i+1)*arraySize/n;

        pthread_create(&threads[i], nullptr, targetSearch, thisThread);
    }

    pthread_mutex_init(&mutex, nullptr);

    for (int i=0; i<n; i++){
        pthread_join(threads[i], nullptr);
    }

    pthread_mutex_destroy(&mutex);

    if (targetFound){
        cout<<"Target found at "<<targetLocation<<"th position in array"<<endl;
    }
    else{
        cout<<"Target not found"<<endl;
    }
}

