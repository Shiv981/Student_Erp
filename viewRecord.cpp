#include <iostream>
#include<map>
#include <fstream>
#include "headers/viewrecord.h"
using namespace std;

void viewRecord() {
    fstream file,tempfile;
    file.open("addrecord.txt", ios::in | ios::out);
    while(file.good()){
        string line;
        getline(file,line);
        cout<<line<<endl;
    }
    file.close();
}
