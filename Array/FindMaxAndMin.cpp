#include <iostream>

using namespace std;

int findMax(int arr[], int size)
{
    int nMin = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > nMin)
            nMin = arr[i];
    }

    return nMin;
}

int findMin(int arr[], int size)
{
    int nMin = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < nMin)
            nMin = arr[i];
    }

    return nMin;
}

int main()
{

    int arr[]{3, 2, 4, 1, 6, 34, 04, 12, 132, 8};

    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << " The maximum element is : " << findMax(arr, size) << endl;
    std::cout << " The minimum element is : " << findMin(arr, size) << endl;

    return 0;
}