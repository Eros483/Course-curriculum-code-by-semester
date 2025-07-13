#include <iostream>

#include <fstream> //enables reading and writinhg files
#include <string> //enables use of string variables instead of char arrays
#include <dirent.h>

#include <unistd.h> //POSIX OS API used to process operations
#include <pwd.h>
#include <sstream>

using namespace std;

using namespace std;

bool ifNumberic(string& str){
    for (char x: str){
        if(!isdigit(x))
        return false;
    }
    return true;
}

void nameProcesses(){
    DIR *procDir=opendir("/proc"); //to open the process files directory

    struct dirent *entry; //structure to read directories
    cout << left << "Process ID\t\tName\t\tStatus\t\t\t\tUser" << endl; //arranging output as asked

    while ((entry = readdir(procDir)) != nullptr){
        if (entry->d_type==DT_DIR){
            string processID=entry->d_name;

            string statusFilePath = "/proc/" + processID + "/status";
            ifstream file(statusFilePath);
            if(!file.is_open()){
                continue;
            }

            string processLine, processName, processStatus;
            uid_t uid = -1;
            while (getline(file, processLine)){
                if (processLine.find("Name:")==0){
                    processName=processLine;
                }
                else if (processLine.find("State:")==0){
                    processStatus=processLine;
                }
                else if (processLine.find("Uid:")==0){
                    istringstream iss(processLine);
                    string temp;
                    iss >> temp >> uid;
                    break;
                } //finding relevant sections of line
            }

            file.close();

            struct passwd *pwd=getpwuid(uid);
            string processUserName = pwd? pwd->pw_name : "Unknown";

            cout<<processID<<"\t\t"<<processName<<"\t\t"<< processStatus<<"\t\t" <<processUserName<<endl;
            } //i.e if it is a directory 
    }
    closedir(procDir);
}

int main(){
    nameProcesses();
}