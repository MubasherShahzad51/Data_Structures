#include <iostream>
using namespace std;

void rearrangeList(int arr[], int size)
{
    int *even = arr;
    int *odd = arr + 1; 

    while (even < arr + size && odd < arr + size)
    {
        while (*even % 2 == 0)
        {
            even += 2;
        }

        while (*odd % 2 != 0)
        {
            odd += 2;
        }

        if (even < arr + size && odd < arr + size)
        {
            int temp = *even;
            *even = *odd;
            *odd = temp;
        }
    }
}

int main()
{
    int arr[] = {5,2,9,4,7,6,1,3,8,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    rearrangeList(arr, size);

    cout << "\nRearranged array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
