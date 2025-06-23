// Talent Hub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

string signUp();
string get_valid_password();
void loggedInMenu(const string& username);

// =======================
// Password Functions
// =======================
// Coded by Matthew
// =======================

template <typename Pred>
bool contains_if(const string& s, Pred p)
{
    return any_of(s.begin(), s.end(), p);
}

struct Result
{
    int score;
    vector<string>tips;
};

// function for evaluating the password and setting the criteria
Result evaluate_password(const string& pw)
{
    Result out{ 0, {} };

    bool long_enough = pw.length() >= 8;
    bool has_upper = contains_if(pw, isupper);
    bool has_lower = contains_if(pw, islower);
    bool has_digit = contains_if(pw, isdigit);
    bool has_special = contains_if(pw, ispunct);

    // each criteria met adds 1 point, they need all 5 to meet requirements
    out.score = static_cast<int>(long_enough)
        + static_cast<int>(has_upper)
        + static_cast<int>(has_lower)
        + static_cast<int>(has_digit)
        + static_cast<int>(has_special);

    // Tips for each section they'll be prompted if not meting any
    if (!long_enough) out.tips.emplace_back("Use at least 8 charcters.");
    if (!has_upper) out.tips.emplace_back("Add an uppercase letter (A-Z).");
    if (!has_lower) out.tips.emplace_back("Add a lowercase leter (a-z).");
    if (!has_digit) out.tips.emplace_back("Include a digit (0-9).");
    if (!has_special) out.tips.emplace_back("Include a special character, e.g (!,@,#,$,%).");

    return out;
}
// gives feedback based on how strong they make the password
string strength_label(int score)
{
    switch (score)
    {
    case 5: return "Very Strong"; // will use this one in a Do While loop for the condition to exit the loop
    case 4: return "Strong";
    case 3: return "Moderate";
    case 2: return "Weak";
    default: return "Very Weak";
    }
}
// =======================

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
        cout << endl;

        password = get_valid_password();

       
        cout << endl;

        cout << "Welcome " << username << "!" << endl;
        cout << "Please fill in the following details!" <<  endl;
        cout << endl;
        cout << "First Name: ";
        cin >> fName;
        cout << "Last Name: ";
        cin >> lName;
        cout << "Age: ";
        cin >> age;
        cout << "Email: ";
        cin >> email;
        cout << "Mobile Number: ";
        cin >> mobile;
        cout << "Current Address: ";
        cin >> address;
        cout << endl;
        //cout << "Are you a domestic or international student?";

        ofstream file; // Creates a txt file to save the user so they have an account.
        file.open(username + ".txt");
        file << username << endl << password << endl << endl << fName << endl << lName << endl << age << endl << email << endl << mobile << endl << address << endl;
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


    // system("pause>0");
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
        cout << endl;
        cout << "1. Introduction to Information Technology" << endl;
        cout << "2. Foundations of Management" << endl;
        cout << "3. Project Management Essentials" << endl;
        cout << "4. English for Academic Purposes" << endl;
        cout << "5. Business Communication" << endl;
        cout << "6. Conversational Languages" << endl;
        cout << endl;
        cout << "New Courses" << endl;
        cout << endl;
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

string get_valid_password()
{
    string password;
    Result res;

    do
    {
        // Tell the user the password conditions
        cout << "***** Password Conditions *****" << endl;
        cout << "Please use an Upper and lower case, a number, " << endl;
        cout << "A special character and be 8 characters long." << endl;
        cout << endl;
        cout << "Enter a Password: ";
        cin >> password;

        res = evaluate_password(password); // Calling the function to evaluate the password after its been input

        cout << "\nPassword Strength: " << strength_label(res.score)
            << " (" << res.score << "/5)\n"; // Gives a score out of 5

        if (!res.tips.empty()) // output the tips for the best practices they haven't followed yet.
        {
            cout << "\nSuggestions:\n";
            for (const string& tip : res.tips)
                cout << "  . " << tip << '\n' << endl;
        }

    } while (res.score < 5); // let the loop end once they have reached a perfect score (followed best practices).
    
    return password;
}

// Need to define a function for displaying the courses and storing which students 
/*void courses()
{

}*/
