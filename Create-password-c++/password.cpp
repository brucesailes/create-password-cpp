#include <iostream>
#include <string>
#include <cctype> // For character type checking

using namespace std;

class PasswordValidator
{
public:
    static bool isStrongPassword(const string &password)
    {
        const int minLength = 10;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasPunct = false;

        for (char c : password)
        {
            if (isupper(c))
            {
                hasUpper = true;
            }
            else if (islower(c))
            {
                hasLower = true;
            }
            else if (isdigit(c))
            {
                hasDigit = true;
            }
            else if (ispunct(c))
            {
                hasPunct = true;
            }
        }

        return hasUpper && hasLower && hasDigit && hasPunct && password.length() >= minLength;
    }
};

int main()
{
    cout << "***** Welcome to my password generator mini project ******" << endl
         << endl;

    cout << "***** You are now about to experience the power of street knowledge hahaha ****" << endl

         << endl;

    string password;
    bool isValidPassword = false;

    while (!isValidPassword)
    {
        cout << "Enter password: ";
        getline(cin, password);

        if (PasswordValidator::isStrongPassword(password))
        {
            isValidPassword = true;
            cout << "Password is strong!" << endl;
        }
        else
        {
            cout << "Password is weak. Please make it stronger." << endl;
        }
    }

    return 0;
}
