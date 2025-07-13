#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

// Function for sorting the array by parent process using Bubble Sort
void parentSort(int a[],int n) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-i-1; ++j) {
            if (a[j]> a[j+1]) {
                swap(a[j],a[j+1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i=0;i<n; i++) {
        cin>>arr[i];
    }

    parentSort(arr, n);

    // Initializing execution arguments
    char arrString[500] = ""; // Large buffer
    char targetString[10];
    char* args[4];

    for (int j=0;j<n;j++) {
        sprintf(arrString + strlen(arrString), "%d ", arr[j]);
    }

    cout << "Enter the number to be found via binary search: ";
    int t;
    cin >> t;
    sprintf(targetString, "%d", t);

    // Arguments for execvp()
    args[0] = (char*)"./child";
    args[1] = arrString;  // Sorted array
    args[2] = targetString;  // Target number
    args[3] = NULL;  // Null terminate argument list

    pid_t pid = fork();

    if (pid<0) {
        cerr<<"Fork failed"<<endl;
        return -1;
    }

    if (pid==0) {
        execvp("./child", args);
        cerr << "Execution failed" << endl;
        _exit(1);  
    }

    int status;
    wait(&status);
    if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        cout << "Child process failed" << endl;
    }

    cout << "Parent process declares Child process has terminated" << endl;
    return 0;
}

/*In order to run the program:
1.open relevant terminal
2.navigate to directory the file is stored in
3.run "g++ -o parent Assgn2Src3-ParentSort-ArnabMandal.cpp"
4.run "g++ -o child Assgn2Src3-ChildSearch-ArnabMandal.cpp"
5.run "./parent"
*/