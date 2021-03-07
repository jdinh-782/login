//
// Created by jdinh on 2/25/2021.
//

#ifndef LOGIN_LOGIN_H
#define LOGIN_LOGIN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;


enum Identifiers
{
    A = '@', B = '#', C = '$', D = '%', E = '&'
};


template <class T>
class Login
{
private:
    vector<T> username;
    vector<T> password;
    string userTemp, passTemp;

public:
    Login();
    //Login(string& usernameInput, string& passwordInput);

    void setUsername();
    void setPassword();
    void confirmUsernameAndPassword();
    void confirmOption(int option);
    void createAccount();
    void loginToAccount();
    void excess();

    int getOption();
    int invalidInput(int num1, int num2, int correctInput);

    bool checkUsername();
    bool checkPassword();

    T getUsername();
    T getPassword();

    ostream& outs(ostream&, Login<T> l) const;
};


#include "Login.cpp"

#endif //LOGIN_LOGIN_H
