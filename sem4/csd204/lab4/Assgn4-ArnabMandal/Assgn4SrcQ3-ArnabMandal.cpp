#include <iostream>
#include <pthread.h>

using namespace std;

int counter=0;
#define numberOfIterations 1000000
pthread_mutex_t mutex;


/*void *incrementCounter(void*){
    for (int i=0;i<numberOfIterations;i++){
        counter++;
    }
    return nullptr;
}*/

void*incrementCounter(void*){
    for (int i=0; i<numberOfIterations; i++){
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return nullptr;
}

int main(){
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, nullptr);

    pthread_create(&t1, nullptr, incrementCounter, nullptr);
    pthread_create(&t2, nullptr, incrementCounter, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    pthread_mutex_destroy(&mutex);

    cout<<"Final Counter Value: "<<counter<<endl;
    return 0;
}

/*
to run the program:
1. open terminal
2. navigate to correct directory
note:
    to run execution without mutex lock, uncomment line 11 to 16 and comment line 18 to 25, and the opposite for implementing with the mutex lock
3. use command "g++ Assgn4SrcQ1-ArnabMandal.cpp -o q3 -pthread"
4. use command "./q3"
*/

