#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

void removeRecord() {
    fstream file, rollno, userid;
    file.open("addrecord.txt", ios::in | ios::out);   
    rollno.open("rollno.txt", ios::in | ios::out);
    userid.open("userid.txt", ios::in | ios::out);

    string rlno;
    cout << "Enter the rollno whose record you want to delete: ";
    cin >> rlno;

    if (!file) {
        cout << "Error opening addrecord file." << endl;
        return;
    }
    if (!rollno) {
        cout << "Error opening rollno file" << endl;
        return;
    }
    if (!file) {
        cout << "Error opening userid file" << endl;
        return;
    }

    queue<string> q;

    string line, line1, line2;
    while (getline(file, line) && getline(rollno, line1) && getline(userid, line2)) {
        if (line1 != rlno) {

//we push the data in the queue in such type like first is full data second is roll no. and third is userid and fourth is again rollno. so we can easily extract the data from queue
        
             q.push(line);
            q.push(line1);
            q.push(line2);
        }
    }

    file.close();
    rollno.close();
    userid.close();

//open the file in trunc mode so that we can overwrite the data easily

    file.open("addrecord.txt", ios::out | ios::trunc);  
    rollno.open("rollno.txt", ios::out | ios::trunc);
    userid.open("userid.txt", ios::out | ios::trunc);



    while (!q.empty()) {

//push the data from queue to empty files again          
        
        string s1, s2, s3;
        s1 = q.front();
        q.pop();
        s2 = q.front();
        q.pop();
        s3 = q.front();
        q.pop();
        file << s1 << endl;
        rollno << s2 << endl;
        userid << s3 << endl;
    }

    file.close();
    rollno.close();
    userid.close();

    cout << "Record with rollno " << rlno << " deleted successfully." << endl;
}
