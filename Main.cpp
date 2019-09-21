#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctime>

#include "MotorClass.h"

using namespace std;

int main()
{
    while (1)
    {

        // LogIn Interface
        string username;
        string password;

        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        if (username == "nipuna" && password == "nipuna")
        {
            cout << "logged in";
            while (1)
            {
                //Instruction window
                cout << "\n//////////Instructions//////////\n\n";
                cout << "1 -> Create a temperature log\n";
                cout << "2 -> Read the temperature of the last 4 weeks\n";
                cout << "3 -> Compare the temperature variance in the last 4 weeks\n\n";

                int inst;
                cout << "Enter instruction number : ";
                cin >> inst;

                if (inst == 1)
                {
                    // Get motor number
                    string motorNumber;
                    cout << "Enter motor number : ";
                    cin >> motorNumber;

                    // Availability of the file
                    ifstream ifile(motorNumber + ".txt");
                    if (ifile)
                    {
                        cout << "File present";

                        int shaftTemp;
                        cout << "Enter motor shaft temperature : ";
                        cin >> shaftTemp;

                        int centerTemp;
                        cout << "Enter motor center temperature : ";
                        cin >> centerTemp;

                        int fanTemp;
                        cout << "Enter fan temperature : ";
                        cin >> fanTemp;

                        // Create a Motor class
                        Motor M;
                        M.number = motorNumber;
                        M.shaftTemp = shaftTemp;
                        M.centerTemp = centerTemp;
                        M.fanTemp = fanTemp;

                        M.create_temp_log();
                    }
                    else
                    {
                        cout << "No file";

                        string motorName;
                        cout << "Enter motor name : ";
                        cin >> motorName;

                        int shaftTemp;
                        cout << "Enter motor shaft temperature : ";
                        cin >> shaftTemp;

                        int centerTemp;
                        cout << "Enter motor center temperature : ";
                        cin >> centerTemp;

                        int fanTemp;
                        cout << "Enter fan temperature : ";
                        cin >> fanTemp;

                        // Create a Motor class
                        Motor M;
                        M.number = motorNumber;
                        M.name = motorName;
                        M.shaftTemp = shaftTemp;
                        M.centerTemp = centerTemp;
                        M.fanTemp = fanTemp;

                        M.new_create_temp_log();
                    }
                }
                else if (inst == 2)
                {
                    // Get motor number
                    string motorNumber;
                    cout << "Enter motor number : ";
                    cin >> motorNumber;

                    Motor M;
                    M.number = motorNumber;

                    M.read_temperature();
                }
                else if (inst == 3)
                {
                    //
                }
                else
                {
                    cout << "Please enter a given instruction\n";
                }
            }
        }
        else
        {
            cout << "Incorrect username or password\n";
        }
    }
}