#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class User
{
public:
    string userID;
    string username;
    string password;

    void createUser()
    {
        string userID;
        cout << "Enter userID : ";
        cin >> userID;

        string username;
        cout << "Enter username : ";
        cin >> username;

        string password;
        cout << "Enter password : ";
        cin >> password;

        // Create a new user
        ofstream file;
        file.open("Users/" + username + ".txt");
        file << userID << endl
             << username << endl
             << password << endl;
        file.close();
    }

    int authUser()
    {
        string ent_username;
        string ent_password;

        // User Authenticating
        cout << "Enter username : ";
        cin >> ent_username;
        cout << "Enter password : ";
        cin >> ent_password;

        ifstream ifile("Users/" + ent_username + ".txt");
        if (ifile)
        {
            int i = 0;
            string STRING;
            ifstream file;
            file.open("Users/" + ent_username + ".txt");
            while (getline(file, STRING))
            {
                if (i == 0)
                {
                    i++;
                    continue;
                }
                else if (i == 1)
                {
                    i++;
                    continue;
                }
                else if (i == 2)
                {
                    if (ent_password == STRING)
                    {
                        return 1;
                    }
                }
                else
                {
                    return 0;
                }
                i++;
            }
        }
        else
        {
            return 0;
        }
        return 0;
    }
};
