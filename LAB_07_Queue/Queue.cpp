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

        if (length == capacity || rear == capacity - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        rear++;
        *(arr + rear) = value;
        length++;
    }
    int dequeue()
    {
        int value = -1;
        if (length == 0 || front == rear)
        {
            cout << "Queue Underflow" << endl;
            return 0;
        }

        front++;
        value = *(arr + front);
        length--;

        return value;
    }

    void print()
    {
        if (length == 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front + 1; i <= rear; i++)
        {
            cout << arr[i] << " ";
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
    Queue q1(6);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.print();

    return 0;
}