#include <iostream>
#include <string>
using namespace std;
struct Node
{
public:
    string description;
    int priority;
    bool completed;
    Node *next;
    Node *prev;

    Node(const string &desc, int pri = 0)
    {
        this->description = desc;
        this->completed = false;
        this->priority = pri;
        this->next = NULL;
        this->prev = NULL;
    }
};
class ToDoList
{
private:
    Node *head;
    Node *tail;

public:
    ToDoList()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void addTask(const string &description, int priority = 0, bool completed = false)
    {
        Node *newTask = new Node(description, priority);
        newTask->completed = completed;

        if (head == NULL)
        {
            head = newTask;
            tail = newTask;
        }
        else
        {
            Node *current = head;
            while (current && current->priority <= priority)
            {
                current = current->next;
            }
            if (current == NULL)
            {
                // Insert at the end
                tail->next = newTask;
                newTask->prev = tail;
                tail = newTask;
            }
            else
            {
                // Insert before current
                if (current->prev)
                {
                    current->prev->next = newTask;
                    newTask->prev = current->prev;
                }
                else
                {
                    head = newTask;
                }
                newTask->next = current;
                current->prev = newTask;
            }
        }
    }
    void markAsCompleted(const string &description)
    {
        Node *current = head;

        while (current)
        {
            if (current->description == description)
            {
                current->completed = true;
                return;
            }
            current = current->next;
        }

        cout << "Task not found." << endl;
    }
    void removeCompletedTasks()
    {
        Node *current = head;

        while (current)
        {
            if (current->completed)
            {
                if (current->prev)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }

                if (current->next)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }

                Node *temp = current;
                current = current->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
    }
    void displayTasks(bool forwardDirection = true)
    {
        Node *current = forwardDirection ? head : tail;

        if (current == NULL)
        {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        while (current)
        {
            cout << "* " << current->description << ":"
                 << " (Task Completed: " << (current->completed ? "Yes" : "No") << ")" << endl;
            current = forwardDirection ? current->next : current->prev;
        }
    }

    ~ToDoList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    ToDoList myList;
    int choice;

    do
    {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark as Completed" << endl;
        cout << "3. Remove Completed Tasks" << endl;
        cout << "4. Display Tasks Forward" << endl;
        cout << "5. Display Tasks Reverse" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        // Clear newline
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string description;
            int priority;
            cout << "Enter the task description: ";
            getline(cin, description);
            cout << "Enter task priority (0 for default): ";
            cin >> priority;
            myList.addTask(description, priority);
            break;
        }
        case 2:
        {
            string description;
            cout << "Enter task description to mark as completed: ";
            getline(cin, description);
            myList.markAsCompleted(description);
            break;
        }
        case 3:
            myList.removeCompletedTasks();
            break;
        case 4:
            myList.displayTasks(true);
            break;
        case 5:
            myList.displayTasks(false);
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
