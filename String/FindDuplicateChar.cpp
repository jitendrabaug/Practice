//this program calculates the count of duplicate characters

#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::string str = "ABCABC";

    std::map<char, int> charCountmap;
    int index{};
    while (index < str.length())
    {
        charCountmap[str[index]]++;
        index++;
    }

    for (auto it = charCountmap.begin(); it != charCountmap.end(); ++it)
    {
        std::cout << it->first << "  " << it->second << endl;
    }
}
