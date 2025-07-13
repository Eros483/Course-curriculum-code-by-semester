#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <vector>
#include <queue>
#include <cstdlib>
#include <chrono>

using namespace std;

queue<int> buffer;
int bufferSize;

mutex bufferMutex;
sem_t emptySlots;
sem_t filledSlots;

void producer(int id){
    while(true){
            
        /*for (int i=0; i<bufferSize; i++){
            int item=rand()%100;

            if (sem_trywait(&emptySlots)!=0){
                cout << "Producer " << id << " is waiting for an empty slot." << endl;
                sem_wait(&emptySlots);
            }

            bufferMutex.lock();
            buffer.push(item);

            cout<<"Producer "<<id<<" produces: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&filledSlots);
        }*///case2

        /*while (sem_trywait(&emptySlots)==0){
            int item=rand()%100;

            bufferMutex.lock();
            buffer.push(item);

            cout<<"Producer "<<id<<" produces: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&filledSlots);
        }*///case1

        for (int i=0; i<bufferSize; i++){
            int item=rand()%100;

            sem_wait(&emptySlots);

            bufferMutex.lock();
            buffer.push(item);

            cout<<"Producer "<<id<<" produces: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&filledSlots);
        }

        this_thread::sleep_for(chrono::milliseconds(500+rand()%500));
    }
}

void consumer(int id){
    while(true){
            
        /*for (int j=0; j<2; j++){    
            if (sem_trywait(&filledSlots)!=0){
                cout<<"Consumer "<<id<<" is waiting for entry in buffer."<<endl;
                sem_wait(&filledSlots);
            }        
            bufferMutex.lock();
            int item=buffer.front();
            buffer.pop();
            cout<<"Consumer "<<id<<"consumed: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&emptySlots);
        }*/
       
        /*while (sem_trywait(&filledSlots)==0){        
            bufferMutex.lock();
            int item=buffer.front();
            buffer.pop();
            cout<<"Consumer "<<id<<"consumed: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&emptySlots);
        }*///case1

        for (int j=0; j<2; j++){    
            sem_wait(&filledSlots);

            bufferMutex.lock();
            int item=buffer.front();
            buffer.pop();
            cout<<"Consumer "<<id<<"consumed: "<<item<<endl;
            bufferMutex.unlock();

            sem_post(&emptySlots);
        }      
        
        this_thread::sleep_for(chrono::milliseconds(500+rand()%500));
    }
}

int main(){
    srand(time(0));

    cout<<"Enter buffer size: "<<endl;
    cin>>bufferSize;

    sem_init(&emptySlots, 0, bufferSize);
    sem_init(&filledSlots, 0, 0);

    int numProducers, numConsumers;
    cout<<"Enter number of producers: "<<endl;
    cin>>numProducers;

    cout<<"Enter number of consumers: "<<endl;
    cin>>numConsumers;

    vector<thread> producers, consumers;

    for (int i=1; i<=numProducers;i++){
        producers.emplace_back(producer, i);
    }

    for (int i=1; i<=numConsumers; i++){
        consumers.emplace_back(consumer, i);
    }

    for (auto &p: producers) p.join();
    for (auto &c: consumers) c.join();

    sem_destroy(&emptySlots);
    sem_destroy(&filledSlots);

    return 0;
}

/*
Instructions to run the program:
1. open terminal and navigate to relevant directory
2. run g++ Assgn5SrcQ1-ArnabMandal.cpp -o q1
3. run ./q1
4. input values as desired
*/



