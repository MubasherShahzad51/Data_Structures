#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int value = arr[top];
        top--;
        return value;
    }
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    bool is_empty()
    {
        if (top == -1)
        {
            return true; 
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack s1(5);
    s1.push(11);
    s1.push(22);
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.print();
    s1.pop();
    s1.pop();
    cout<<"Peek: "<<s1.peek()<<endl;
    s1.pop();
    s1.pop();
    s1.print();
    cout<<"Peek: "<<s1.peek()<<endl;
    s1.pop();
    if(s1.is_empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    };
    s1.print();

    return 0;
}