#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Motor
{
public:
    // Motor details
    char *dateTime;
    string number;
    string name;

    // Temperature details of the mortor
    int shaftTemp;
    int centerTemp;
    int fanTemp;

    //Create a temperature log
    void new_create_temp_log()
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        ofstream file;
        file.open("Motors/" + number + ".txt");
        file << number << endl
             << name << endl;
        file << "shaft Temp"
             << ","
             << " center Temp"
             << ","
             << "fan Temp"
             << ","
             << "Date and Time"
             << endl;
        file << shaftTemp << "," << centerTemp << "," << fanTemp << "," << dateTime;
        file.close();
    }

    void create_temp_log()
    {
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        ofstream file;
        file.open("Motors/" + number + ".txt", ios::app);
        file << shaftTemp << "," << centerTemp << "," << fanTemp << "," << dateTime;
        file.close();
    }

    //Read the temperature of the last 4 weeks
    void read_temperature()
    {

        int i = 0;
        vector<string> array;
        string STRING;
        ifstream file;
        file.open("Motors/" + number + ".txt");
        cout << "__________________________________________";
        while (getline(file, STRING))
        {
            if (i == 0)
            {
                cout << "Motor Number : ";
                cout << STRING << endl;
            }
            else if (i == 1)
            {
                cout << "Name of the motor : ";
                cout << STRING << endl;
            }
            else if (i == 2)
            {
                cout << STRING << "\n"
                     << endl;
            }
            else
            {
                //cout << STRING << endl;
                array.push_back(STRING);
            }
            i++;
        }

        // Print the last 4 records
        int j = 0;
        reverse(array.begin(), array.end());
        for (int i = 0; i < array.size(); i++)
            if (i == 4)
            {
                break;
            }
            else
            {
                cout << array[i] << "\n";
            }

        cout << "__________________________________________";
    }

    //Compare the temperature variance in the last 4 weeks
    void analyze_temperature()
    {
        //
    }
};
