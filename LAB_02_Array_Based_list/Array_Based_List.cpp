#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class ArrayList
{
private:
    int *arr;
    int length;
    int capacity;
    int *curr;

public:
    ArrayList(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        curr = arr;
        length = 0;
    }

    void start()
    {
        curr = arr;
    }
    void tail()
    {
        curr = arr + length - 1;
    }
    void next()
    {
        curr++;
    }
    void back()
    {
        curr--;
    }
    void print()
    {
        start(); // Ensure curr points to the start of the array
        for (int i = 0; i < length; i++)
        {
            cout << *(curr + i) << " ";
        }
        cout << endl;
    }
    void insert(int pos, int val)
    {
        if (length == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        tail();
        for (int i = length; i >= pos; i--)
        {
            *(curr + 1) = *curr;
            back();
        }
        *(curr + 1) = val;
        length++;
    }

    ~ArrayList()
    {
        delete[] arr;
    }
};

int main()
{
    ArrayList l1(5);
    l1.insert(1, 10);
    l1.insert(2, 20);
    l1.insert(3, 30);
    l1.print();

    return 0;
}
