#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char val)
    {
        this->data = val;
        this->next = NULL;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
    }

    void push(char val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
        {
            cerr << "Stack Underflow." << endl;
            return '\0';
        }

        char val = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack undo;
    Stack redo;
    string input;
    string currentString = "";

    cout << "Enter a string: ";
    cin >> input;

    for (int i = 0; i < input.length(); ++i)
    {
        char c = input[i];
        currentString += c;
        undo.push(c);
    }
    char choice;
    do
    {
        cout << "Current String: " << currentString << endl;

        cout << "Enter your Choice: 1 for Undo, 2 for Redo, 3 to Quit: ";
        cin >> choice;

        if (choice == '1')
        {
            if (!undo.isEmpty())
            {
                char poppedChar = undo.pop();
                currentString.pop_back();
                redo.push(poppedChar);
            }
            else
            {
                cout << "Nothing to do" << endl;
            }
        }
        else if (choice == '2')
        {
            if (!redo.isEmpty())
            {
                char poppedChar = redo.pop();
                currentString += poppedChar;
                undo.push(poppedChar);
            }
        }

    } while (choice != '3');

    cout << "Final String: " << currentString << endl;

    return 0;
}
