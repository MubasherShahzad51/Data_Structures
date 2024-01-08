#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int capacity;
    int *arr;
    int length;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        length = 0;
    }

    void enqueue(int value)
    {

        if (length == capacity)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        if (rear == capacity - 1)
        {
            rear = 0;
        }

        else
        {
            rear++;
        }

        *(arr + rear) = value;
        length++;
    }
    int dequeue()
    {
        int value = -1;
        if (length == 0)
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        value = *(arr + front);
        if (front == capacity - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        length--;

        return value;
    }

    void print()
    {
        if (length == 0)
        {
            return;
        }

        cout << "Queue elements: ";
        int index = front + 1;
        for (int i = 0; i < length; i++)
        {
            cout << arr[index] << " ";
            if (index == capacity - 1)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        cout << endl;
    }

    // void swapQueue()
    // {

    //     int start = 0;
    //     int end = length - 1;

    //     while (start < end)
    //     {
    //         swap(*(arr + start), *(arr + end));
    //         start++;
    //         end--;
    //     }
    // }
};

int main()
{
    Queue q1(5);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.dequeue();
    q1.enqueue(10);
    q1.dequeue();
    q1.enqueue(11);
    q1.print();

    return 0;
}