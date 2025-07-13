#include <iostream>
#include <sys/utsname.h>
using namespace std;

int main(){
    struct utsname sysInfo; //structure defined in sys header, stores info aboutsystem architecture

    if (uname(&sysInfo)==0){
        cout<<"Config of the system:" <<endl;
        cout<<"OS: " <<sysInfo.sysname <<endl;
        cout<<"Release: "<<sysInfo.release<<endl;
        cout<<"Version: "<<sysInfo.version<<endl;
        cout<<"Machine: "<<sysInfo.machine<<endl;
    }

    return 0;
}