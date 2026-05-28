#include "../include/ComputerLab.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    ComputerLab lab;
    char op;

    while (cin >> op) {
        if (op == '=') {
            break;
        }

        if (op == '+') {
            string userID;
            int labNum, stationNum;
            cin >> userID >> labNum >> stationNum;

            User* u = lab.findOrCreateUser(userID);
            loginReq req = { u, labNum, stationNum, false };
            lab + req;

            if (!req.flag) {
                cout << "invalid login" << endl;
            }
            lab.displayStatus();
        } else if (op == '-') {
            string userID;
            cin >> userID;

            User* u = lab.findOrCreateUser(userID);
            logoffReq req = { u, false };
            lab - req;

            if (!req.flag) {
                cout << "invalid logoff" << endl;
            }
            lab.displayStatus();
        }
    }

    lab.displayStatus();
    return 0;
}
