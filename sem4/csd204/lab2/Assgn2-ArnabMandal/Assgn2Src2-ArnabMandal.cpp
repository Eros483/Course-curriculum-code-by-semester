#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;

void killProcess(pid_t pid) {
    if (kill(pid, SIGTERM) == 0) {
        cout << "Process " << pid << " terminated successfully." << endl;
    } else {
        perror("Error terminating process");
    }
}

void printState(pid_t pid) {
    string path = "/proc/" + to_string(pid) + "/status";
    ifstream file(path);

    if (!file.is_open()) {
        cerr << "Process has finished"<< endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("State:") != string::npos) {
            cout << "Process State: " << line << endl;
            break;
        }
    }
    file.close();
}

// Function for parent sorting process, using bubble sort
void parentSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

//function for child sorting process, using selection sort
void childSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

// Function to print the array for increased convenience
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value of element a[" << i << "]" << endl;
        cin >> a[i];
    } // Receiving array value

    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed" << endl;
        return -1;
    } // Fork failure

    else if (pid == 0) {
        // Child process

        cout << "Child process sorting begins: " << endl;
        childSort(a, n);
        cout << "Child has sorted array: ";
        printArray(a, n);
        cout << "Child (pid=" << getpid() << ") process is running" << endl;
        printState(getpid());
        cout << "Child process work finished, now exiting." << endl;
        cout<<"process state check after child process exit " <<endl;
        printState(pid);
        
        //Orphan process creation steps        
        //-----
        /*for(int i=0; i<20; i++){
            cout<<"Child process sleeping for "<<20-i<<" seconds."<<endl;
            sleep(1);
        }
        cout<<"child process: "<<getpid()<<", parent process of this child: "<<getppid()<<endl;*/
        //-----

        cout<<"child process exits now"<<endl;
        exit(0); // Child process exits, becomes a zombie if the parent does not reap it
    }

    else {
        // Parent process

        cout << "Parent process sorting begins" << endl;
        parentSort(a, n);
        cout << "Parent has sorted array: ";
        cout<<"process state check after parent process sort " <<endl;
        printState(pid);
        printArray(a, n);
        
        //-----
        //orphan process creation path
        /*cout<<"Parent " <<getpid() <<" exits"<<endl;
        exit(0);*/
        //-----

        //-----
        //zombie process creation path
        sleep(10);
        cout<<"process state check after parent process sleep " <<endl; //Checking child's state, should be 'Z (zombie)'
        printState(pid);
        cout << "Parent process ends, child process (if still a zombie) will be reaped by init." << endl;
        //zombie process creation path ends
        //-----

        //-----
        //normal code execution path, comment out if zombie is to be observed
        /*wait(NULL);
        cout<<"process state check after parent process wait "<<endl;
        printState(pid);*/
        //normal code execution path ends
        //-----
    }

    cout<<"This is the original process"<<endl;

    return 0;
}

/* How to run the program:
1. Open terminal, navigate to directory the file is stored in
2.  To observe zombie:
        uncomment lines 131-134

    To carry out regular flow:
        uncomment lines 140-142

    To observe orphan"
        uncomment lines 102-106 & 125-126


3. Compile: g++ Assgn2Src2-ArnabMandal.cpp -o q2
4. Run: ./q2
*/
