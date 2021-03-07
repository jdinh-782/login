//
// Created by jdinh on 2/25/2021.
//
#ifndef LOGIN_LOGIN_CPP
#define LOGIN_LOGIN_CPP

#include "Login.h"


template <class T>
Login<T>::Login()
{
    username.reserve(4);
    password.reserve(8);
}


//template<class T>
//Login<T>::Login(string& usernameInput, string& passwordInput)
//{
//    for (char& i : usernameInput)
//    {
//        username.push_back(i);
//    }
//    for (char& i : passwordInput)
//    {
//        password.push_back(i);
//    }
//}


template<class T>
void Login<T>::setUsername()
{
    cout << "\nEnter a unique username (minimum 4 characters): ";
    cin >> userTemp;
}


template<class T>
void Login<T>::setPassword()
{
    cout << "\nEnter a unique password (minimum 8 characters): ";
    cin >> passTemp;
}


template <class T>
bool Login<T>::checkUsername()
{
    if (userTemp.size() < 4)
    {
        cout << "\nUsername must be at least 4 characters long. You inputted " << userTemp;
        return false;
    }
    else
    {
        for (auto& letter : userTemp)
        {
            if (letter == A || letter == B || letter == C || letter == D || letter == E)
            {
                return true;
            }
        }
        cout << "\nUsername should include at least one of the following: @, #, $, %, &. You inputted " << userTemp;
        return false;
    }
}


template <class T>
bool Login<T>::checkPassword()
{
    if (passTemp.size() < 8)
    {
        cout << "\nPassword must be at least 8 characters long. You inputted " << passTemp;
        return false;
    }
    else if (passTemp.find_first_of("pass") != string::npos)
    {
        cout << "\nPassword contains letters from the word \"pass\". Try a different password! You inputted " << passTemp;
        return false;
    }
    else
    {
        int num = 0;
        for (auto& letter : passTemp)
        {
            if (letter == A || letter == B || letter == C || letter == D || letter == E)
            {
                num++;
            }
        }
        if (num >= 3)
        {
            return true;
        }
        cout << "\nPassword should include at least three of the following: @, #, $, %, &. You inputted " << passTemp;
        return false;
    }
}


template <class T>
void Login<T>::confirmUsernameAndPassword()
{
    for (auto& letter : userTemp)
    {
        username.push_back(letter);
    }
    for (auto& letter : passTemp)
    {
        password.push_back(letter);
    }
    //implement saving login details to file
}


template <class T>
void Login<T>::excess()
{
    char c;

    do
    {
        cin.get(c);
    } while (c != '\n');
}


template <class T>
int Login<T>::invalidInput(int num1, int num2, int correctInput)
{
    while (cin.fail() || correctInput < num1 || correctInput > num2)
    {
        cout << "Invalid input! Enter again: ";
        cin.clear();
        excess();
        cin >> correctInput;
    }
    return correctInput;
}


template<class T>
int Login<T>::getOption()
{
    int choice;
    cout << "[1] Login To An Existing Account\n"
            "[2] Create Account\n"
            "[3] Exit\n"
            "Enter option: ";
    cin >> choice;
    choice = invalidInput(1, 3, choice);

    return choice;
}


template<class T>
void Login<T>::confirmOption(int option)
{
    if (option == 3)
    {
        exit(1);
    }
    else if (option == 1)
    {
        loginToAccount();
    }
    else if (option == 2)
    {
        createAccount();
    }
}


template<class T>
void Login<T>::createAccount()
{
    while (true)
    {
        setUsername();
        if (checkUsername())
        {
            while (true)
            {
                setPassword();
                if (checkPassword())
                {
                    break;
                }
            }
            break;
        }
    }
    confirmUsernameAndPassword();
}


template<class T>
void Login<T>::loginToAccount()
{
    ifstream ifs;
    ifs.open("file.txt");
    string userAttempt, passAttempt;
    char text;
    vector<char> v, v1, v2;

    cout << "\nUsername: ";
    cin >> userAttempt;
    for (auto& i : userAttempt)
    {
        v1.push_back(i);
    }

    cout << "Password: ";
    cin >> passAttempt;
    for (auto& i : passAttempt)
    {
        v2.push_back(i);
    }

    while (ifs >> text)
    {
        v.push_back(text);
    }
    ifs.close();

    v.erase(v.begin(), v.begin() + 9);

    int i;
    for (i = 0; i < v.size(); i++)
    {
        if (v[i] == 'p' && v[i+1] == 'a' && v[i+2] == 's' && v[i+3] == 's')
        {
            break;
        }
        username.push_back(v[i]);
    }
    v.erase(v.begin(), v.begin() + i + 9);

    for (auto& counter : v)
    {
        password.push_back(counter);
    }

    for (i = 0; i < v1.size(); i++)
    {
        if (v1[i] != username[i])
        {
            cout << "\nUsername is incorrect!";
            exit(1);
        }
    }

    for (i = 0; i < v2.size(); i++)
    {
        if (v2[i] != password[i])
        {
            cout << "\nPassword is incorrect!";
            exit(1);
        }
    }

//    for (auto& counter : username)
//    {
//        cout << counter << " ";
//    }
//    cout << endl;
//
//    for (auto& counter : password)
//    {
//        cout << counter << " ";
//    }
    cout << "\nLogin successful!";
    exit(1);
}


template<class T>
ostream& Login<T>::outs(ostream& outs, Login<T> l) const
{
    outs << "username: ";
    for (auto& i : l.username)
    {
        outs << i;
    }

    outs << "\npassword: ";
    for (auto& i : l.password)
    {
        outs << i;
    }
    return outs;
}


#endif //LOGIN_LOGIN_CPP