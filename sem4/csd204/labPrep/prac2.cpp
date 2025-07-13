#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

struct threadData{
    int i;
    int start;
    int end;
};

#define n 10
int arraySum=0;

#define randomArraySize 100

vector<int> arr(randomArraySize);
vector<int> arrOfPartialSums(n);

pthread_mutex_t mutex;

void randomArrayGenerator(){
    srand(time(0));
    for(int i=0; i<randomArraySize; i++){
        arr[i] = rand() % 10;
    }
}

void* arrayPartialSums(void* args){
    threadData* threadSum=(threadData*)args;
    int start = threadSum->start;
    int end=threadSum->end;
    int i=threadSum->i;
    arrOfPartialSums[i]=0;
    for (int j=start; j<end; j++){
        arrOfPartialSums[i]+=arr[j];
    }
    pthread_mutex_lock(&mutex);
    arraySum+=arrOfPartialSums[i];
    pthread_mutex_unlock(&mutex);

    delete threadSum;
    return nullptr;
}

int main(){
    pthread_t threads[n];

    randomArrayGenerator();

    for (int i=0; i<randomArraySize; i++){
        cout<<arr[i]<<" "<<endl;
    }

    for (int i=0; i<n; i++){
        threadData* newThreadData=new threadData;
        newThreadData->i=i;
        newThreadData->start=i*randomArraySize/n;
        newThreadData->end=(i==n-1)?randomArraySize:(i+1)*randomArraySize/n;

        pthread_create(&threads[i], nullptr, arrayPartialSums, newThreadData);
    }

    pthread_mutex_init(&mutex, nullptr);

    for (int i=0; i<n; i++){
        pthread_join(threads[i], nullptr);
    }

    pthread_mutex_lock(&mutex);

    cout<<"Array Sum is: "<<arraySum<<endl;
}