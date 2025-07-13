#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
    int n;

    cout<<"Enter number of child processes: "; //entering number of child processes as instructed in question
    cin>>n;

    if (n<1 || n>10){
        cout<<"Invalid input." <<endl; //paramenters of n as mentioned
        return 1;
    }

    for (int i=0; i<n; i++){
        pid_t pid=fork();

        if (pid<0){
            cout<<"Fork failed"<<endl;//fork failure
        }

        if (pid==0){
            cout<<"Hello, I am a child process. My pid is: " << getpid() <<endl;
            exit(0);
        }

        else{
            wait(NULL);
        }

    }

    cout<<"Hello, I am a parent process. My pid is: "<<getpid()<<endl;
    return 0;
}

/*In order to run the program:
1.open relevant terminal
2.navigate to directory the file is stored in
3.run "g++ Assgn2Src1-ArnabMandal.cpp -o q1"
4.run "./q1"
*/


