#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

atomic<int> lock_flag(false);
int n, k;
double lambda1, lambda2;
ofstream output_file;

void exp_delay(double lambda){
    static thread_local mt19937 generator(random_device{}());
    exponential_distribution<double> dist(1.0/lambda);
    this_thread::sleep_for(milliseconds(static_cast<int>(dist(generator))));
    //generating sleep time via exponential distribution
}

void cas_lock(){
    int expected=0;
    while(!lock_flag.compare_exchange_strong(expected, 1, memory_order_acquire)){
        expected=0;
    }
}

void cas_unlock(){
    lock_flag.store(0, memory_order_release);
}

void testCS(int thread_id){
    for(int i=0; i<k; i++){
        auto req_time=system_clock::now();
        output_file<<i+1<<"th CS requested at "<<duration_cast<milliseconds>(req_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        cas_lock();

        auto entry_time=system_clock::now();
        output_file<<i+1<<"th CS entered at "<<duration_cast<milliseconds>(entry_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        exp_delay(lambda1);

        auto exit_time=system_clock::now();

        output_file<<i+1<<"th CS exited at "<<duration_cast<milliseconds>(exit_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;

        cas_unlock();
        
        exp_delay(lambda2);
    }
}

int main(){
    ifstream input_file("inp-params.txt");
    output_file.open("Assgn6Src-ArnabMandal-CaS_output.txt");

    input_file>>n>>k>>lambda1>>lambda2;
    vector<thread> threads;

    for (int i=0; i<n; i++){
        threads.emplace_back(testCS,i+1);
    }

    for (auto &t:threads){
        t.join();
    }

    output_file.close();
    cout<<"CAS ME test completed. Output saved to Assgn6Src-ArnabMandal-CaS_output.txt" <<endl;
    return 0;
}

/*
Instructions:
1. Modify inp-params.txt with necessary parameters
2. Open terminal, and navigate to the proper directory
3. Compile the code using "g++ Assgn6Src-ArnabMandal-CaS.cpp -o Cas"
4. Enter "./Cas"
5. observe output in the output file
*/