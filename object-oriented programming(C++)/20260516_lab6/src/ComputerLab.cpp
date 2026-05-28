#include "../include/ComputerLab.h"
#include <iostream>

User::User(const string& id) {
    ID = id;
    loggedIn = false;
    labNum = 0;
    stationNum = 0;
}

string User::getID() const {
    return ID;
}

bool User::isLoggedIn() const {
    return loggedIn;
}

ComputerLab::ComputerLab() {
    stationCounts[0] = 5;
    stationCounts[1] = 6;
    stationCounts[2] = 4;
    stationCounts[3] = 3;

    for (int i = 0; i < LAB_COUNT; i++) {
        for (int j = 0; j < 6; j++) {
            stationUsers[i][j] = nullptr;
        }
    }
}

ComputerLab::~ComputerLab() {
    for (User* u : users) {
        delete u;
    }
}

User* ComputerLab::findOrCreateUser(const string& id) {
    for (User* u : users) {
        if (u->ID == id) {
            return u;
        }
    }
    User* newUser = new User(id);
    users.push_back(newUser);
    return newUser;
}

void ComputerLab::operator+(loginReq& r) {
    User* u = r.userPointer;
    int labIdx = r.labNum - 1;
    int stationIdx = r.stationNum - 1;

    if (u->loggedIn) {
        r.flag = false;
        return;
    }

    if (labIdx < 0 || labIdx >= LAB_COUNT ||
        stationIdx < 0 || stationIdx >= stationCounts[labIdx]) {
        r.flag = false;
        return;
    }

    if (stationUsers[labIdx][stationIdx] != nullptr) {
        r.flag = false;
        return;
    }

    stationUsers[labIdx][stationIdx] = u;
    u->loggedIn = true;
    u->labNum = r.labNum;
    u->stationNum = r.stationNum;
    r.flag = true;
}

void ComputerLab::operator-(logoffReq& r) {
    User* u = r.userPointer;

    if (!u->loggedIn) {
        r.flag = false;
        return;
    }

    int labIdx = u->labNum - 1;
    int stationIdx = u->stationNum - 1;

    stationUsers[labIdx][stationIdx] = nullptr;
    u->loggedIn = false;
    u->labNum = 0;
    u->stationNum = 0;
    r.flag = true;
}

void ComputerLab::displayStatus() const {
    for (int i = 0; i < LAB_COUNT; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < stationCounts[i]; j++) {
            if (stationUsers[i][j] != nullptr) {
                cout << j + 1 << ": " << stationUsers[i][j]->ID << " ";
            } else {
                cout << j + 1 << ": empty ";
            }
        }
        cout << endl;
        cout << endl;
    }
}
