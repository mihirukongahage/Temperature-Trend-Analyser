#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

// Function to split a string
// Return a vector of type string
// This function tokenize a string with a given delimiter
vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Motor class
class Motor
{
public:
    // Motor details
    char *dateTime; // Date and time
    string number;  // Motor number
    string name;    // Motor name

    // Temperature details of the mortor
    int shaftTemp;
    int centerTemp;
    int fanTemp;

    //Create a new temperature log
    void new_create_temp_log()
    {
        // Get the current date and time
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        // Write a log to the file
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
        file << shaftTemp << " " << centerTemp << " " << fanTemp << " " << dateTime;
        file.close();
    }

    // Create a temperature log to an existing file
    void create_temp_log()
    {
        // Motor details
        time_t now = time(0);
        char *dt = ctime(&now);
        dateTime = dt;

        // Write a log to the file
        ofstream file;
        file.open("Motors/" + number + ".txt", ios::app);
        file << shaftTemp << " " << centerTemp << " " << fanTemp << " " << dateTime;
        file.close();
    }

    //Read the temperature of the last 4 weeks
    void read_temperature()
    {

        int i = 0;
        // Initialize a vector of type string
        vector<string> array;
        string STRING;
        ifstream file;
        file.open("Motors/" + number + ".txt");
        while (getline(file, STRING))
        {
            if (i == 0)
            {
                // Print the motor number
                cout << "Motor Number : ";
                cout << STRING << endl;
            }
            else if (i == 1)
            {
                // Print the motor name
                cout << "Name of the motor : ";
                cout << STRING << endl;
            }
            else if (i == 2)
            {
                // Print the header string
                cout << STRING
                     << endl;
            }
            else
            {
                // Push the file row to the vector
                array.push_back(STRING);
            }
            i++;
        }

        // Print the last 4 records
        int j = 0;
        // Reverse the vector to get the latest data first
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
    }

    //Compare the temperature variance in the last 4 weeks
    void analyze_temperature()
    {
        int i = 0;
        vector<string> array;
        string STRING;
        ifstream file;
        file.open("Motors/" + number + ".txt");
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
        int arr_shaft[4];
        int arr_center[4];
        int arr_fan[4];

        reverse(array.begin(), array.end());
        for (int i = 0; i < array.size(); i++)
            if (i == 4)
            {
                break;
            }
            else
            {
                string values[3];
                // Split the row and insert it into vector v
                vector<string> v = split(array[i], ' ');
                int j = 0;
                for (auto i : v)
                {
                    if (j > 2)
                    {
                        break;
                    }
                    else
                    {
                        // Push the values to a new array 'values'
                        values[j] = i;
                    }
                    j++;
                }

                // Convert the string vector to int vector
                vector<int> int_v;
                for (int k = 0; k < 4; k++)
                {
                    int num = atoi(v.at(k).c_str());
                    int_v.push_back(num);
                }

                // 3 new arrays to store details
                arr_shaft[i] = int_v[0];
                arr_center[i] = int_v[1];
                arr_fan[i] = int_v[2];
            }

        // For shaft
        cout << "Shaft Temperature Data\n";
        for (int m = 0; m < 4; m++)
        {
            cout << "Week " << m + 1 << " : " << arr_shaft[4 - m - 1] << endl;
        }
        if (arr_shaft[0] >= arr_shaft[1])
        {
            cout << "Warning!!! Shaft Temperature Increased\n";
        }
        cout << '\n';

        // For center
        cout << "Center Temperature Data\n";
        for (int m = 0; m < 4; m++)
        {
            cout << "Week " << m + 1 << " : " << arr_center[4 - m - 1] << endl;
        }
        if (arr_center[0] >= arr_center[1])
        {
            cout << "Warning!!! Center Temperature Increased\n";
        }
        cout << '\n';

        // For fan
        cout << "Fan Temperature Data\n";
        for (int m = 0; m < 4; m++)
        {
            cout << "Week " << m + 1 << " : " << arr_fan[4 - m - 1] << endl;
        }
        if (arr_fan[0] >= arr_fan[1])
        {
            cout << "Warning!!! Fan Temperature Increased\n";
        }
        cout << '\n';
    }
};
