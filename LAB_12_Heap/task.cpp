#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;
class Patient
{
public:
    string name;
    int urgency;
    Patient(string name, int urgency)
    {
        this->name = name;
        this->urgency = urgency;
    }
};
class Heap
{
public:
    vector<Patient> htree;
    int getParent(int child)
    {
        if (child < 0)
        {
            return -1;
        }
        return (child - 1) / 2;
    }
    int getLeft(int parent)
    {
        return 2 * parent + 1;
    }
    int getRight(int parent)
    {
        return 2 * parent + 2;
    }
    void swap(Patient *a, Patient *b)
    {
        Patient temp = *a;
        *a = *b;
        *b = temp;
    }
    void heapifyUp(int node)
    {
        while (node > 0 && htree[node].urgency < htree[getParent(node)].urgency)
        {
            swap(&htree[node], &htree[getParent(node)]);
            node = getParent(node);
        }
    }
    void heapifyDown(int node)
    {
        int left_child = getLeft(node);
        int right_child = getRight(node);
        int smallest_node = node;

        if (left_child < htree.size() && htree[left_child].urgency < htree[smallest_node].urgency)
        {
            smallest_node = left_child;
        }

        if (right_child < htree.size() && htree[right_child].urgency < htree[smallest_node].urgency)
        {
            smallest_node = right_child;
        }

        if (smallest_node != node)
        {
            swap(&htree[node], &htree[smallest_node]);

            heapifyDown(smallest_node);
        }
    }
    void insert(Patient patient)
    {
        htree.push_back(patient);
        heapifyUp(htree.size() - 1);
    }
    void del()
    {
        if (htree.empty())
        {
            cout << "No appointments to delete." << endl;
            return;
        }

        swap(&htree[0], &htree[htree.size() - 1]);
        htree.pop_back();
        heapifyDown(0);
    }
    void updateUrgency(string patientName, int new_Urgency)
    {
        for (int i = 0; i < htree.size(); i++)
        {
            if (htree[i].name == patientName)
            {
                int previous_urgency_level = htree[i].urgency;
                htree[i].urgency = new_Urgency;

                if (new_Urgency < previous_urgency_level)
                {
                    heapifyUp(i);
                }
                else
                {
                    heapifyDown(i);
                }

                return;
            }
        }

        cout << "Patient not found." << endl;
    }
    void display()
    {
        if (htree.empty())
        {
            cout << "No appointments to display." << endl;
            return;
        }
        cout << "Current Appointments:" << endl;
        for (int i = 0; i < htree.size(); i++)
        {
            cout << "Name: " << htree[i].name << ", Urgency: " << htree[i].urgency << endl;
        }
        cout << endl;
    }
};
void displayMenu()
{
    cout << "Menu:" << endl;
    cout << "1. Schedule Patient Appointment" << endl;
    cout << "2. Send Next Patient to the Doctor (Deletion) " << endl;
    cout << "3. Update Patient Urgency" << endl;
    cout << "4. View Appointments" << endl;
    cout << "5. Exit" << endl;
}
int main()
{
    Heap priorityQueue;

    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Schedule Patient Appointment:" << endl;
            string name;
            int urgency;
            cout << "Enter patient's name: ";
            cin >> name;
            cout << "Enter urgency level: ";
            cin >> urgency;

            priorityQueue.insert(Patient(name, urgency));
            break;
        }
        case 2:
        {
            cout << "Sending next patient to the doctor (Deletion):" << endl;
            priorityQueue.del();
            break;
        }
        case 3:
        {
            cout << "Update Urgency:" << endl;
            string name;
            int urgency;
            cout << "Enter patient's name for urgency update: ";
            cin >> name;
            cout << "Enter new urgency level: ";
            cin >> urgency;
            priorityQueue.updateUrgency(name, urgency);
            break;
        }
        case 4:
        {
            priorityQueue.display();
            break;
        }
        case 5:
        {
            cout << "Exiting program." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
        }

    } while (choice != 5);

    return 0;
}