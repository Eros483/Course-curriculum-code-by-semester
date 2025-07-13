#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <sstream>
#include <algorithm>
using namespace std;

void listProcesses() {
    DIR *procDir = opendir("/proc");
    if (!procDir) {
        cerr << "Error: Unable to open /proc directory." << endl;
        return;
    }

    struct dirent *entry;
    cout << left << "PID\tNAME\t\tSTATUS\tUSER" << endl;

    while ((entry = readdir(procDir)) != nullptr) {
        if (entry->d_type == DT_DIR) {
            string pid = entry->d_name;
            if (!all_of(pid.begin(), pid.end(), ::isdigit)) {
                continue;
            }

            string statusFile = "/proc/" + pid + "/status";
            ifstream file(statusFile);
            if (!file.is_open()) {
                continue;
            }

            string line, name, status;
            uid_t uid = -1;
            while (getline(file, line)) {
                if (line.find("Name:") == 0) {
                    name = line.substr(line.find_last_of('\t') + 1);
                } else if (line.find("State:") == 0) {
                    status = line.substr(line.find_last_of('\t') + 1);
                } else if (line.find("Uid:") == 0) {
                    istringstream iss(line);
                    string temp;
                    iss >> temp >> uid;
                    break;
                }
            }
            file.close();

            struct passwd *pwd = getpwuid(uid);
            string username = pwd ? pwd->pw_name : "Unknown";

            cout << pid << "\t" << name << "\t" << status << "\t" << username << endl;
        }
    }
    closedir(procDir);
}

int main() {
    listProcesses();
    return 0;
}
