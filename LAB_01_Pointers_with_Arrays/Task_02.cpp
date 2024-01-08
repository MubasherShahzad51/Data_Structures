#include <iostream>
#include <cstring>
using namespace std;
bool isPalindrome(const char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i)
    {
        if (*(str + i) != *(str + len - i - 1))
        {
            return false;
        }
    }
    return true;
}

int countCharacter(const char *str, char target)
{
    int count = 0;
    while (*str)
    {
        if (*str == target)
        {
            ++count;
        }
        ++str;
    }
    return count;
}

int main()
{
    char input[100];
    char choice;
    char selected_Char;

    cout << "Enter a string without spaces: ";
    cin >> input;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Check if the string is palindrome.\n";
        cout << "2. Count the frequency of a certain character.\n";
        cout << "3. Exit.\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            if (isPalindrome(input))
            {
                cout << "The string is a palindrome.\n";
            }
            else
            {
                cout << "The string is not a palindrome.\n";
            }
            break;
        case '2':
            cout << "Enter the character to count: ";
            cin >> selected_Char;
            cout << "Frequency of '" << selected_Char << "' in the string: "
                 << countCharacter(input, selected_Char) << "\n";
            break;
        case '3':
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != '3');

    return 0;
}