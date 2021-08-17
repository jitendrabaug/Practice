#include <iostream>
#include <algorithm>
using namespace std;

//finding min and max

int findkMax(int arr[], int size)
{
    return 0;
}

int findKMin(int arr[], int size)
{
    return 0;
}

int main()
{

    int arr[]{3, 2, 4, 1, 6, 34, 04, 12, 132, 8};

    std::sort(arr, arr + 10);

    int *val = std::unique(arr, arr + 10);

    std::cout << "The discard value is : " << *val << endl;
    ;

    for (int i : arr)
        std::cout << i << " ";

    std::cout << endl;

    return 0;
}
