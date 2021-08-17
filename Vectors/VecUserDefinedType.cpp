
#include <vector>
#include <iostream>

using namespace std;

class Sample
{
    // Copy Constructor should not be private if we are inserting it's
    // objects in std::vector

public:
    Sample()
    {
        std::cout << "Sample :: Default Constructor" << std::endl;
    }
    Sample &operator=(const Sample &obj)
    {
        std::cout << "Sample :: Assignment Operator" << std::endl;
    }
    Sample(const Sample &obj)
    {
        std::cout << "Sample :: Copy Constructor" << std::endl;
    }
};
int main()
{
    std::vector<Sample> vecOfSamples(2);
    Sample obj;
    vecOfSamples.push_back(obj);
    return 0;
}