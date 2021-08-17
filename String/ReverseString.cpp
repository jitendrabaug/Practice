#include <iostream>
#include <string>
using namespace std;

std::string reverseString(std::string str, int nStart, int nEnd)
{
    while (nStart < nEnd)
    {
        char temp = str[nStart];
        str[nStart] = str[nEnd];
        str[nEnd] = temp;
        nStart++;
        nEnd--;
    }

    return str;
}

void RecursiveReverse(std::string &str, int nStart, int nEnd)
{
    if (nStart > nEnd)
        return;

    char temp = str[nStart];
    str[nStart] = str[nEnd];
    str[nEnd] = temp;

    RecursiveReverse(str, ++nStart, --nEnd);
}

int main()
{
    std::string str{"ABCBA"};

    int nStart = 0;
    int nEnd = str.length() - 1;
    std::string str1 = reverseString(str, nStart, nEnd);
    //RecursiveReverse(str, nStart, nEnd);

    std::cout << str.compare(str1) << std::endl;
    return 0;
}