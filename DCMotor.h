
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class DCMotor
{
public:
    int Nr; // Rotational Speed
    int S;  // Normalized slip

    char *dateTime; // Date and time
    string number;  // Motor number
    string name;    // Motor name

    //Create a new temperature log
    void new_create_motor_log()
    {
        // Get motor data
        string number;
        string name;
        int Nr;
        int S;

        cout << "___Enter Motor Details___";
        cout << "Enter Motor Number";
        cin >> number;
        cout << "Enter Motor Name";
        cin >> name;
        cout << "Enter Motor Rotational Speed";
        cin >> Nr;
        cout << "Enter Motor Slip";
        cin >> S;

        // Get the current date and time
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        // Write a log to the file
        ofstream file;
        file.open("DCMotors/" + number + ".txt");
        file << number << endl
             << name << endl;
        file << "Rotational Speed"
             << ","
             << "Slip"
             << ","
             << "Date and Time"
             << endl;
        file << Nr << " " << S << " " << dateTime;
        file.close();
    }

    // Create a temperature log to an existing file
    void create_motor_log()
    {
        // Motor details
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        // Write a log to the file
        ofstream file;
        file.open("DCMotors/" + number + ".txt", ios::app);
        file << Nr << " " << S << " " << dateTime;
        file.close();
    }
};
