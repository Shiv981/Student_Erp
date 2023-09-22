#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "headers/addrecord.h"

using namespace std;

void addRecord() {
    fstream file;
    fstream rollno_file;
    fstream userid_file;
    file.open("addrecord.txt", ios::out | ios::app);
    rollno_file.open("rollno.txt", ios::in); // Open for reading initially
    userid_file.open("userid.txt", ios::out | ios::app);

    if (!file.is_open()) {
        cout << "add record is not open" << endl;
    }
 if (!file.is_open()) {
        cout << "add record is not open" << endl;
    }
if (!userid_file.is_open()) {
        cout << "roll no. is not open" << endl;
    }
 else {
        string rollnum, pass, sname, snumber, spname, spreclg, stper, stwper;

        cout << "Enter the roll number: ";
        cin >> rollnum;

        int flag = 0;
        string rn;
        while (getline(rollno_file, rn)) {
            if (rn == rollnum) {
                flag = 1;
                break;
            }
        }

        rollno_file.close(); // Close the read-only file

        if (flag == 0) {
            cout << "Enter the password for student: ";
            cin >> pass;
            cout << "Enter the student name: ";
            cin >> sname;
            cout << "Enter the student number: ";
            cin >> snumber;
            cout << "Enter the student father's name: ";
            cin >> spname;
            cout << "Enter the student previous college name: ";
            cin >> spreclg;
            cout << "Enter the student 10th percentage: ";
            cin >> stper;
            cout << "Enter the student 12th percentage: ";
            cin >> stwper;

            // Write data to respective files
            file << rollnum << setw(20) << pass << setw(20) << sname << setw(20) << snumber << setw(20)
                 << spname << setw(20) << spreclg << setw(20) << stper << setw(20) << stwper << endl;
            rollno_file.open("rollno.txt", ios::out | ios::app); // Reopen in append mode
            rollno_file << rollnum << endl; // Write the roll number to "rollno.txt"
            userid_file << pass << endl;   // Write the user ID to "userid.txt"
        } else {
            cout << "Record already exists with this roll number" << endl<<endl;
        }

        // Close the files
        file.close();
        rollno_file.close();
        userid_file.close();
    }
}
