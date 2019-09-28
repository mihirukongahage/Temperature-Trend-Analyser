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

        // User Authenticating
        cout << "Enter username : ";
        cin >> username;
        cout << "Enter password : ";
        cin >> password;
        if (username == "nipuna" && password == "nipuna")
        {
            cout << "logged in\nUser " << username << endl;
            while (1)
            {
                //Instruction window
                cout << "\n//////////Instructions//////////\n\n";
                cout << "1 -> Create a temperature log\n";
                cout << "2 -> Read the temperature of the last 4 weeks\n";
                cout << "3 -> Compare the temperature variance in the last 4 weeks\n";
                cout << "4 -> Exit\n\n";

                //Get the user instruction number as 'inst'
                int inst;
                cout << "Enter instruction number : ";
                cin >> inst;

                // If the user instruction is 1-> Create a new temperature log
                if (inst == 1)
                {
                    // Get motor number
                    string motorNumber;
                    cout << "Enter motor number : ";
                    cin >> motorNumber;

                    // Availability of the file
                    ifstream ifile("Motors/" + motorNumber + ".txt");
                    // If the motor is available in the database
                    if (ifile)
                    {
                        cout << "Motor details available\n";

                        //Get shaft temperature as 'shaftTemp'
                        int shaftTemp;
                        cout << "Enter motor shaft temperature : ";
                        cin >> shaftTemp;

                        //Get shaft temperature as 'centerTemp'
                        int centerTemp;
                        cout << "Enter motor center temperature : ";
                        cin >> centerTemp;

                        //Get shaft temperature as 'fanTemp'
                        int fanTemp;
                        cout << "Enter fan temperature : ";
                        cin >> fanTemp;

                        // Create a Motor class
                        Motor M;
                        M.number = motorNumber;    // Unique number to identify the motor
                        M.shaftTemp = shaftTemp;   // Shaft temperature
                        M.centerTemp = centerTemp; // Center temperature
                        M.fanTemp = fanTemp;       // Fan temperature

                        // Class method to log temperature details
                        M.create_temp_log();
                    }
                    else
                    {
                        cout << "No motor details available\n";

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

                        // Create a new temperature log
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

                    // Read temperature method
                    M.read_temperature();
                }
                else if (inst == 3)
                {
                    // Get motor number
                    string motorNumber;
                    cout << "Enter motor number : ";
                    cin >> motorNumber;

                    Motor M;
                    M.number = motorNumber;
                    // Analyze temperature
                    M.analyze_temperature();
                }
                else if (inst == 4)
                {
                    exit(1);
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