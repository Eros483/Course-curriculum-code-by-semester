#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>
#include <mutex>

using namespace std;
using namespace chrono;

atomic<int> lock_flag(0);
atomic<int> next_ticket(0);
vector<atomic<bool>*> waiting;
mutex file_mutex;

int n, k;
double lambda1, lambda2;
ofstream output_file;

void exp_delay(double lambda){
    static thread_local mt19937 generator(random_device{}());
    exponential_distribution<double> dist(1.0/lambda);
    this_thread::sleep_for(milliseconds(static_cast<int>(dist(generator))));
    //generating sleep time via exponential distribution
}

void bounded_cas_unlock(int thread_id){
    lock_flag.store(lock_flag.load(memory_order_relaxed)+1, memory_order_release);
    waiting[thread_id]->store(false);
}

void bounded_cas_lock(int thread_id){
    waiting[thread_id]->store(true);
    int ticket=next_ticket.fetch_add(1, memory_order_acquire);

    while(lock_flag.load(memory_order_acquire)!=ticket);
}

void testCS(int thread_id){
    for(int i=0; i<k; i++){
        auto req_time=system_clock::now();
        {
            lock_guard<mutex> guard(file_mutex);
            output_file<<i+1<<"th CS requested at "<<duration_cast<milliseconds>(req_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;   
        }
        bounded_cas_lock(thread_id);

        auto entry_time=system_clock::now();
        {
            lock_guard<mutex> guard(file_mutex);
            output_file<<i+1<<"th CS entered at "<<duration_cast<milliseconds>(entry_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;
        }
        
        exp_delay(lambda1);

        auto exit_time=system_clock::now();
        {
            lock_guard<mutex> guard(file_mutex);
            output_file<<i+1<<"th CS exited at "<<duration_cast<milliseconds>(exit_time.time_since_epoch()).count()<<" by thread "<<thread_id<<endl;
        }

        bounded_cas_unlock(thread_id);
        
        exp_delay(lambda2);
    }
}

int main(){
    ifstream input_file("inp-params.txt");
    output_file.open("Assgn6Src-ArnabMandal-boundedCaS_output.txt");
    
    input_file>>n>>k>>lambda1>>lambda2;
    
    for(int i=0; i<n; i++){
        waiting.emplace_back(new atomic<bool>(false));  // Initialize each element properly
    }

    vector<thread> threads;

    for (int i=0; i<n; i++){
        threads.emplace_back(testCS,i);
    }

    for (auto &t:threads){
        t.join();
    }

    output_file.close();
    cout<<"bounded CAS ME test completed. Output saved to Assgn6Src-ArnabMandal-boundedCaS_output.txt" <<endl;
    return 0;
}

/*
Instructions:
1. Modify inp-params.txt with necessary parameters
2. Open terminal, and navigate to the proper directory
3. Compile the code using "g++ Assgn6Src-ArnabMandal-boundedCaS.cpp -o boundedCas"
4. Enter "./boundedCas"
5. observe output in the output file
*/
