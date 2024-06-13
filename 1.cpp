#include <bits/stdc++.h>
#include <windows.h>
#include <sstream>
#include <fstream>
using namespace std;

class Account {
private:
    string AccountNo;
    string Password;
    int Balance;
public:
    Account() : AccountNo(""), Password(""), Balance(0) {} //constructor
    void setAccountNo(string id) {
        AccountNo = id;
    }
    void setPassword(string pw) {
        Password = pw;
    }
    void setBalance(int balance) {
        Balance = balance;
    }
    string getAccountNo() {
        return AccountNo;
    }
    string getPassword() {
        return Password;
    }
    int getBalance() {
        return Balance;
    }
};

void openAccount(Account& user) {
    system("cls");
    string id, password;

    cout << "\t Enter Account No:";
    cin >> id;
    user.setAccountNo(id);

    cout << "\t Enter a strong Password:";
    cin >> password;
    user.setPassword(password);

    user.setBalance(0);

    ofstream outfile("data.txt", ios::app);

    if (!outfile) {
        cout << "\t Error: File can't open!!" << endl;
    } else {
        outfile << user.getAccountNo() << ":" << user.getPassword() << ":" << user.getBalance() << endl;
        cout << "\t Account created Successfully" << endl;
    }
    outfile.close();
    Sleep(5000);
}
//2
void AddCash() {
    system("cls");
    string id;
    cout << "\t Enter your Account Number:";
    cin >> id;

    ifstream infile("data.txt");
    ofstream outfile("temp_data.txt");

    if (!infile || !outfile) {
        cout << "\t ERROR: File can't be opened!!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        stringstream ss(line);
        string userid, userPW;
        int userBalance;
        char delimiter;

        // Parse the line
        getline(ss, userid, ':');
        getline(ss, userPW, ':');
        ss >> userBalance;

        if (id == userid) {
            found = true;
            int cash;
            cout << "\t Enter Cash Amount:";
            cin >> cash;

            int newBalance = userBalance + cash;
            outfile << userid << ":" << userPW << ":" << newBalance << endl;
            cout << "\t Available Balance: " << newBalance << endl;
        } else {
            outfile << line << endl;
        }
    }

    if (!found) {
        cout << "\t INVALID Account Number!!" << endl;
        cout << "\t Enter a valid Account Number:" << endl;
    }

    infile.close();
    outfile.close();
    remove("data.txt");
    rename("temp_data.txt", "data.txt");
    Sleep(5000);
}
//3
void withdraw(){
    string id, pw;
    cout << "Enter Account No:";
    cin >> id;
    cout << "Enter password:";
    cin >> pw;

    ifstream infile("data.txt");
    ofstream outfile("temp_data.txt");
    if(!infile || !outfile){
        cout << "\t Error! file can't open" << endl;
        return;
    }

    string line;
    bool found = false;
    while(getline(infile, line)){
        stringstream ss(line);
        string userId, userPw;
        int userBalance;
        char delimiter;

        // Parse the line using ':' delimiter
        getline(ss, userId, ':');
        getline(ss, userPw, ':');
        ss >> userBalance;

        if(id == userId && pw == userPw){
            found = true;
            int cash;
            cout << "\t Enter Cash:";
            cin >> cash;
            if(cash <= userBalance){
                int newBalance = userBalance - cash;
                outfile << userId << ":" << userPw << ":" << newBalance << endl;
                cout << "\t Transaction Successful" << endl;
                cout << "\t Remaining Balance:" << newBalance << endl;
            }
            else{
                cout << "Insufficient Balance!!" << endl;
                outfile << userId << ":" << userPw << ":" << userBalance << endl;
            }
        }
        else{
            outfile << line << endl;
        }
    }

    if(!found){
        cout << "INVALID Account no. or Password!" << endl;
    }
    infile.close();
    outfile.close();
    remove("data.txt");
    rename("temp_data.txt", "data.txt");
    Sleep(5000);
}

int main() {
    Account user;
    bool exit = false;
    system("cls"); //this is used for clearing previous operations..isfunction ka jo output hai woii display hoga.

    while (!exit) {
        int val;
        cout << "\t WELCOME TO BANK ACCOUNT MANAGEMENT SYSTEM" << endl;
        cout << "****************************************************" << endl;
        cout << "\t1. Open New Account" << endl;
        cout << "\t2. Add Cash" << endl;
        cout << "\t3. Withdraw Cash" << endl;
        cout << "\t4. Exit" << endl;
        cout << "\t Enter Your choice:" << endl;

        cin >> val;

        if (val == 1) {
            openAccount(user);
        } 
        else if (val == 2) {
            AddCash();
        }
        else if( val == 3){
            withdraw();
        }
        else if (val == 4) {
            system("cls");
            exit = true;
            cout <<"ThankYou for Visiting:-)"<<endl;
            cout <<"Have a good day!!"<<endl;
            Sleep(2000);
        }

        Sleep(3000); // iske use se 3000 milliseconds mtlb 3s tk output screen pe rhega
    }
}
