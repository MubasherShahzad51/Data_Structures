#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areBracketsMatching(const string &str)
{
    stack<char> bracketsStack;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            bracketsStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (bracketsStack.empty() ||
                (ch == ')' && bracketsStack.top() != '(') ||
                (ch == ']' && bracketsStack.top() != '[') ||
                (ch == '}' && bracketsStack.top() != '{'))
            {
                return false; // Mismatched brackets or closing bracket without an opening bracket
            }
            bracketsStack.pop();
        }
    }

    return bracketsStack.empty(); // If the stack is empty, all brackets have been matched
}

int main()
{
    string input;

    cout << "Enter a string with brackets: ";
    getline(cin, input);

    if (areBracketsMatching(input))
    {
        cout << "Brackets are matched." << endl;
    }
    else
    {
        cout << "Brackets are not matched." << endl;
    }

    return 0;
}
