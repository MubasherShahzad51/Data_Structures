#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
public:
    char *string;
    int top;
    int capacity;

    Stack(int size)
    {
        string = new char[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] string;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(char item)
    {
        if (!isFull())
        {
            string[++top] = item;
        }
    }

    char pop()
    {
        if (!isEmpty())
        {
            return string[top--];
        }
        return '\0';
    }
};

void reverseString(char input[])
{
    int len = strlen(input);
    Stack stack(len);

    for (int i = 0; i < len; ++i)
    {
        stack.push(input[i]);
    }

    for (int i = 0; i < len; ++i)
    {
        input[i] = stack.pop();
    }
}

int main()
{
    char input[20]; 

    cout << "Enter a string: ";
    cin.getline(input, 20); 

    cout << "Original string: " << input << endl;

    reverseString(input);

    cout << "Reversed string: " << input << endl;

    return 0;
}
