// Talent Hub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <array>

using namespace std;

string signUp();
void loggedInMenu(const string& username);

int main()
{



    //prompt the user to login or signup
    int choice;

    cout << "---------- Welcome ---------- \n";
    cout << "------- To Talent Hub ------- \n";
    cout << endl;
    cout << "1. Sign-Up" << endl;
    cout << "2. Login" << endl;
    cout << "3. Close App" << endl;
    cout << endl;
    cin >> choice; // Get the users choice

    if (choice == 1) // If they choose to sign up then regester them on the system.
    {
        string username, password, fName, lName, age, email, mobile, address, domestic, international;

        cout << "Registration: " << endl;
        cout << endl;
        cout << "Enter a Username: "; // Currently no restictions what their username could be.
        cin >> username;
        cout << "Enter a Password: "; // Not currently using best practices, will need to implement that.
        cin >> password;
        cout << endl;

        cout << "Welcome " << username << "!" << endl;
        cout << "Please fill in the following details!" <<  endl;
        cout << endl;
        cout << "First Name: " << endl;
        cin >> fName;
        cout << "Last Name: " << endl;
        cin >> lName;
        cout << "Age: " << endl;
        cin >> age;
        cout << "Email: " << endl;
        cin >> email;
        cout << "Mobile Number: " << endl;
        cin >> mobile;
        cout << "Current Address: " << endl;
        cin >> address;
        cout << endl;

        ofstream file; // Creates a txt file to save the user so they have an account.
        file.open(username + ".txt");
        file << username << endl << password << endl << endl << fName << endl << lName << endl << age << endl << email << endl << mobile << endl << address;
        file.close();

        // Takes you to the logged in Menu once the users file is created.
        loggedInMenu(username);

        // Set up a system for makeing a list of domestic and international students.
        /*cout << "Where are you situated?" << endl;
        cout << "1. Domestic" << endl;
        cout << "2. International" << endl;
        cin>>*/


    }
    else if (choice == 2)
    {
        string username = signUp();

        if (username == "") // if signUp returns false (doesn't match) then output an error message.
        {
            system("cls");
            cout << "*****Invalid Login!*****" << endl;
            cout << endl;
            main();
            return 0;
        }
        else
        {
            loggedInMenu(username);
        }
        return 1;
    }
     
    else if (choice == 3)
    {
        return 0;
    }


    system("pause>0");
}

string signUp()
{
    string username, password;
    string un, pw; //comparison strings for an extra layer of security

    cout << "Enter a Username: ";
    cin >> username;
    cout << "Enter a Password: ";
    cin >> password;

    ifstream read(username + ".txt"); // ifstream reads if the file is there 
    getline(read, un); //reads the username
    getline(read, pw);// reads the password

    if (un == username && pw == password) //if un and pw are the same as username and password, it will return true
    {
        return username;
    }
    else
    {
        return "";
    }
}

void loggedInMenu(const string& username)
{
    int choiceTwo;

    //Display Homepage
    cout << "Successfully logged in!" << endl;
    cout << "Welcome back!" << endl;
    cout << endl;
    // cout << "Here are your current courses: " << endl; // Need to insert the course function and list here.
    cout << endl;
    cout << "1. Sign Out" << endl;
    cout << "2. Display my details" << endl;;
    cout << "3. Display the list of courses" << endl;
    cout << "4. Close Program" << endl; // This also bring them to the main homepage but still logged in. 
    cin >> choiceTwo;

    if (choiceTwo == 1)
    {
        main(); // Returns to the beggining of the main() function, restarts the app
    }
    else if (choiceTwo == 2)
    {
        ifstream file;
        file.open(username + ".txt");

        if (!file.is_open())
        {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
        loggedInMenu(username);
    }
    else if (choiceTwo == 3)
    {
        // Need to create a function and call it inside this one.
        cout << "These are the list of the courses: " << endl;
        cout << "1. Introduction to Information Technology" << endl;
        cout << "2. Foundations of Management" << endl;
        cout << "3. Project Management Essentials" << endl;
        cout << "4. English for Academic Purposes" << endl;
        cout << "5. Business Communication" << endl;
        cout << "6. Conversational Languages" << endl;
        cout << "New Courses" << endl;
        cout << "7. CISCO" << endl;
        cout << "8. Microsoft certification" << endl;
    }
    else if (choiceTwo == 4)
    {
        system("exit"); // exits the program
    }
    else
    {
        cout << "Invalid option, choose another option.";
        loggedInMenu(username);
    }
}

// Need to define a function for displaying the courses and storing which students 
void courses()
{

}


