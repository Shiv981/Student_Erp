#include <iostream>
#include"headers/addrecord.h"
#include"headers/admin.h"
#include <iomanip>
#include"headers/removerecord.h"
#include"headers/viewrecord.h"
#include"headers/cls.h"
using namespace std;

void adminLogin() {
    cout << "*********WELCOME TO ADMIN SECTION********" << endl;
    string userid, password;
    cout << "Enter your user id: ";
    cin >> userid;
    cout << "Enter your password: ";
    cin >> password; 
     int a=0;
        while (true) {
            if (userid == "Admin" && password == "1234"){
            int choice;
            cout << "****1. Want to view all records****" << endl;
            cout << "****2. Add record******************" << endl;
            cout << "****3. Remove record***************" << endl;
            cout << "****4. Exit*************************" << endl;
            cout<<"**Enter your choice**: ";
            cin >> choice;
            if (choice == 1) {
                cls();
                viewRecord();
                cout<<"want to continue(y/n): ";
                char s;
                cin>>s;
                if(s=='n')
                break;

            }
            if (choice == 2) {
                addRecord();
            }
            if (choice == 3) {
                  removeRecord();
                cout << "Record removed successfully" << endl;
            }
            if (choice == 4) {
                cout << "Exiting" << endl;
                break;
            }
            if (choice > 4) {
                cout << "Invalid Entry" << endl;
                break;
            }
        }
        else{
   a++;
   if(a<=3){
   cout<<"Userid and Password doesn't match try again"<<endl;
   cout << "Enter your user id: ";
    cin >> userid;
    cout << "Enter your password: ";
    cin >> password; 
}
else{
    cls();
    cout<<"Your maximum attempt is finished please try after some time: "<<endl;
     cout<<"Are you a Human (y/n): ";
     char c;
     cin>>c;
     if(c=='n')
     break;
     else
      a=0;
}

     }
    }


}
