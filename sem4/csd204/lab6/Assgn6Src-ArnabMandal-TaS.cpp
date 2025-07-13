#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

atomic<bool> lock_flag(false);
int n, k;
double lambda1, lambda2;
ofstream output_file;

void exp_delay(double lambda){
    static thread_local mt19937 generator(random_device{}());
    exponential_distribution<double> dist(1.0/lambda);
    this_thread::sleep_for(milliseconds(static_cast<int>(dist(generator))));
    //generating sleep time via exponential distribution
}

void tas_lock(){
    while(lock_flag.exchange(true, memory_order_acquire));//spinnning lock until condition acquired
}

void tas_unlock(){
    lock_flag.store(false, memory_order_release);//releasing lock
}

void testCS(int thread_id){
    for(int i=0; i<k; i++){
        auto req_time=system_clock::now();
        output_file<<i+1<<"th CS requested at "<<duration_cast<milliseconds>(req_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        tas_lock();

        auto entry_time=system_clock::now();
        output_file<<i+1<<"th CS entered at "<<duration_cast<milliseconds>(entry_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        exp_delay(lambda1);

        auto exit_time=system_clock::now();

        output_file<<i+1<<"th CS exited at "<<duration_cast<milliseconds>(exit_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        tas_unlock();
        
        exp_delay(lambda2);
    }
}

int main(){
    ifstream input_file("inp-params.txt");
    output_file.open("Assgn6Src-ArnabMandal-TaS_output.txt");

    input_file>>n>>k>>lambda1>>lambda2;
    vector<thread> threads;

    for (int i=0; i<n; i++){
        threads.emplace_back(testCS,i+1);
    }

    for (auto &t:threads){
        t.join();
    }

    output_file.close();
    cout<<"TAS ME test completed. Output saved to Assgn6Src-ArnabMandal-TaS_output.txt" <<endl;
    return 0;
}

/*
Instructions:
1. Modify inp-params.txt with necessary parameters
2. Open terminal, and navigate to the proper directory
3. Compile the code using "g++ Assgn6Src-ArnabMandal-TaS.cpp -o Tas"
4. Enter "./Tas"
5. observe output in the output file
*/