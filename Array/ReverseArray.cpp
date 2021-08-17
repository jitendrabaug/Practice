#include <iostream>
using namespace std;

/*
this is an iterative method   and sololy depends on exchanging the first and last  characters and this 
can also be done with recursive methods

*/

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int i = 0, j = sizeof(arr) / sizeof(int);
    --j;

    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    for (int i : arr)
    {
        std::cout << i << " ";
    }

    std::cout << endl;

    return 0;
}