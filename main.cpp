#include <iostream>
#include "headers/student.h"
#include "headers/admin.h"
#include "headers/cls.h"

using namespace std;

int main() {
    cout << "*********WELCOME TO STUDENT MANAGEMENT SYSTEM********" << endl;
    while (true) {
        cls();    //clear screen function
        int choice;
        cout << "****1.Admin Login****" << endl;
        cout << "****2.Student Login****" << endl;
        cout << "****3.Exit****" << endl;
        cout << "**Enter your Choice**: ";
        cin >> choice;  // Give input for whether you are an admin or student
        if (choice == 1) {
            adminLogin();    //call the admin function
        } else if (choice == 2) {
            studentLogin();   //calling the student function
            cout<<"you want to continue(y/n): ";
            char  c;
            cin>>c;
            if(c=='n')
             break;
        } else if (choice == 3) {
            cout << "Exiting" << endl;
            break;
        } else {
            cout << "Invalid entry" << endl;
            break;
        }
    }
    return 0;
}
