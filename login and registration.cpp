// ?TASK 2: Login and Registration System
#include <iostream>
#include <fstream>
using namespace std;
class User 
{
    string username;
    string password;
    string filepath;
    bool fileExists(const string& filename) 
    {
        ifstream file(filename.c_str());
        return file.good();
    }
public:
    void registerUser() 
    {
        cout<<"=== Register ===\n";
        cout<<"Enter username: ";
        cin.ignore();
        getline(cin,username);
        filepath=username+".txt";
        if (fileExists(filepath)) 
        {
            cout<<"Username already exists. Try another.\n";
            return;
        }
        cout<<"Enter password: ";
        cin>>password;
        ofstream fout(filepath.c_str());
        fout<<username<<endl;
        fout<<password<<endl;
        fout.close();
        cout<<"Registration successful\n";
    }
    void loginUser() {
        cout<<"=== Login ===\n";
        cout<<"Enter username: ";
        cin.ignore();
        getline(cin,username);
        cout<<"Enter password: ";
        cin>>password;
        filepath=username+".txt";
        ifstream fin(filepath.c_str());
        if (!fin.is_open()) 
        {
            cout << "User not found.\n";
            return;
        }
        string storedUsername, storedPassword;
        getline(fin, storedUsername);
        getline(fin, storedPassword);
        fin.close();
        if (username==storedUsername && password==storedPassword) 
        {
            cout<<"Login successful. Welcome, "<<username<<endl;
        } else 
        {
            cout << "Invalid username or password.\n";
        }
    }
};
int main() 
{
    User user;
    int choice;
    while (true) 
    {
        cout<<"\n===== MENU =====\n";
        cout<<"1. Register\n";
        cout<<"2. Login\n";
        cout<<"3. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice) 
        {
            case 1:
                user.registerUser();
                break;
            case 2:
                user.loginUser();
                break;
            case 3:
                cout<<"Exiting----\n";
                return 0;
            default:
                cout<<"Invalid choice. Try again.\n";
        }
}
return 0;
}
