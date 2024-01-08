#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <string>

using namespace std;

class Queue
{
private:
    string *arr;
    int front, rear, size, capacity;

public:
    Queue(int max_Capacity)
    {
        capacity = max_Capacity;
        arr = new string[capacity];
        front = rear = size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool is_empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_full()
    {
        if (size == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(const string &patient)
    {
        if (!is_full())
        {
            arr[rear] = patient;
            rear = (rear + 1) % capacity;
            size++;
            cout << "Patient " << patient << " now waiting in the queue." << endl;
        }
        else
        {
            cout << "The waiting area is full. Cannot add more patients." << endl;
        }
    }

    void dequeue()
    {
        if (!is_empty())
        {
            string patient = arr[front];
            front = (front + 1) % capacity;
            size--;
            cout << "Patient " << patient << " now with the doctor." << endl;
        }
        else
        {
            cout << "No more patients in the queue." << endl;
        }
    }

    void next_patient()
    {
        if (!is_empty())
        {
            cout << "Next Patient in queue: " << arr[front] << endl;
        }
        else
        {
            cout << "No more patients in the queue." << endl;
        }
    }

    void display_queue()
    {
        if (!is_empty())
        {
            cout << "Patients in queue:" << endl;
            int index = front;
            for (int i = 0; i < size; i++)
            {
                cout << arr[index] << endl;
                index = (index + 1) % capacity;
            }
        }
        else
        {
            cout << "No patients in the queue." << endl;
        }
    }
};

int main()
{
    cout << "Enter the maximum capacity of the waiting area: ";
    int max_Capacity;
    cin >> max_Capacity;
    cin.ignore(); 

    Queue patientQueue(max_Capacity);

    while (true)
    {
        cout << "Enter an option:" << endl;
        cout << "1. Add Patient to Queue" << endl;
        cout << "2. Send next patient to the doctor" << endl;
        cout << "3. See who's next" << endl; 
        cout << "4. Display Patient Queue" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string patientName;
            cout << "Enter the name of the patient: ";
            cin.ignore(); 
            getline(cin, patientName);
            patientQueue.enqueue(patientName);
            break;
        }
        case 2:
        {
            patientQueue.dequeue();
            break;
        }
        case 3:
        {
            patientQueue.next_patient();
            break;
        }
        case 4:
        {
            patientQueue.display_queue();
            break;
        }
        default:
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    }

    return 0;
}
