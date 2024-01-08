#include <iostream>
using namespace std;
class Stack
{
public:
    int *stack;
    int top;
    int capacity;

    Stack(int size)
    {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    ~Stack()
    {
        delete[] stack;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int value)
    {
        if (!isFull())
        {
            stack[++top] = value;
            cout<<"Element: "<<value<<" is pushed"<<endl;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop()
    {
        if (!isEmpty())
        {
            cout<<"Element: "<<stack[top]<<" is popped"<<endl;
            return stack[top--];
        }
        else
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }
};

int main()
{
    int size_of_stack;
    cout << "Enter the size of the stack: ";
    cin >> size_of_stack;
    Stack num_of_Stack(size_of_stack);
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    num_of_Stack.push(num1);
    num_of_Stack.push(num2);

    num1 = num_of_Stack.pop();
    num2 = num_of_Stack.pop();

    cout << "After swapping, First Number is: " << num1 << endl;
    cout << "After swapping, Second Number is: " << num2 << endl;

    return 0;
}

