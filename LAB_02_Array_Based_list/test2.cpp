#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
class ArrayList
{
private:
    char *Array;
    int size;
    int capacity;

public:
    ArrayList() : size(0), capacity(10)
    {
        Array = new char[capacity];
    }

    ~ArrayList()
    {
        delete[] Array;
    }

    void insert(char c, int position)
    {
        if (position < 0 || position > size || size >= capacity)
        {
            cout << "Invalid position or array is full." << endl;
            return;
        }

        for (int i = size; i > position; --i)
        {
            Array[i] = Array[i - 1];
        }
        Array[position] = c;
        size++;
    }

    void remove(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position." << endl;
            return;
        }

        for (int i = position; i < size - 1; ++i)
        {
            Array[i] = Array[i + 1];
        }
        size--;
    }

    bool search(char c)
    {
        for (int i = 0; i < size; ++i)
        {
            if (Array[i] == c)
            {
                return true;
            }
        }
        return false;
    }

    void printList()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << Array[i] << " ";
        }
        cout << endl;
    }

    char get(int index)
    {
        if (index >= 0 && index < size)
        {
            return Array[index];
        }
        else
        {
            throw out_of_range("Index out of bounds");
        }
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    ArrayList arrList;
    arrList.insert('e', 0);
    arrList.insert('f', 1);
    arrList.insert('a', 2);
    arrList.insert('b', 3);
    arrList.insert('i', 4);
    arrList.insert('r', 5);

    string target = "fariba";

    for (char c : target)
    {
        if (arrList.search(c))
        {
            int position = 0;
            for (int i = arrList.getSize() - 1; i >= 0; --i)
            {
                if (arrList.get(i) == c)
                {
                    position = i;
                    break;
                }
            }
            arrList.remove(position);
        }
        else
        {
            cout << "Character " << c << " not found." << endl;
            break;
        }
    }

    arrList.printList();

    return 0;
}