#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(const string &data)
    {
        Node *new_Location = new Node;
        new_Location->data = data;
        new_Location->next = top;
        top = new_Location;
    }

    bool isEmpty() 
    {
        return top == NULL;
    }

    bool pop()
    {
        if (isEmpty())
        {
            return false; 
        }

        Node *temp = top;
        top = top->next;
        delete temp;
        return true;
    }


    void print() 
    {
        if (!isEmpty())
        {
            cout << "You are now at: " << top->data << endl;
        }
        else
        {
            cout << "You have not even entered the cave." << endl;
        }
    }
};

int main()
{
    Stack stack;
    int choice;

    while (true)
    {
        cout << "Welcome to the cave!" << endl;
        cout << "Must put your location info in a stack so that you can go back whenever you see a ghost." << endl;
        cout << "Enter a choice:" << endl;
        cout << "1. Go forward in the cave." << endl;
        cout << "2. Go back." << endl;
        cout << "3. Run from the cave, I saw the ghost." << endl;
        cin >> choice;

        if (choice == 1)
        {
            string location_Name;
            cout << "Mark your current location, so that you can go back." << endl;
            cout << "Enter the data of the current location: "<<endl;
            cin >> location_Name;
            stack.push(location_Name);
        }
        else if (choice == 2)
        {
            if (!stack.pop())
            {
                cout << "The stack is empty. You have not marked any locations yet." << endl;
            }
        }
        else if (choice == 3)
        {
            stack.print();
            while (stack.pop())
            {
                stack.print();
            }
            cout << "You successfully ran away from the cave." << endl;
            break;
        }
    }

    return 0;
}
