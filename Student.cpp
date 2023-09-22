#include <iostream>
#include <fstream>
#include <string>
#include "headers/student.h"
using namespace std;

void studentLogin() {
    string rollnum, pass;
    cout << "Enter your roll number: ";
    cin >> rollnum;
    cout << "Enter your password: ";
    cin >> pass;

    ifstream file("addrecord.txt");
    ifstream rollno("rollno.txt");
    ifstream userid("userid.txt");

    if (!file.is_open()) {
        cerr << "Failed to open record file." << endl;
        return;
    }
    if (!rollno.is_open()) {
        cerr << "Failed to open rollno file." << endl;
        return;
    }
    if (!userid.is_open()) {
        cerr << "Failed to open userid file." << endl;
        return;
    }


    string line, str1, str2;

    while (file.good()) {
        getline(file,line);
        getline(rollno, str1);
        getline(userid, str2);

        // Check if rollnum and pass match with the data in the files
        
            if (rollnum == str1 && pass == str2) {
            cout << line << endl;
            break;
        }
    }

    file.close();
    rollno.close();
    userid.close();
}
