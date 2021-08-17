#include <iostream>

using namespace std;

unsigned int countSetBitsUtil(unsigned int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2);
}

int main()
{
    int n = 7;
    cout << "Number of set bits of " << n << " are :" << countSetBitsUtil(n) << endl;
    return 0;
}