#include <iostream>
#include <thread>
using namespace std;
class DummyClass
{
public:
    DummyClass() {}
    DummyClass(const DummyClass &obj) {}

    void sampleFunClass(int x)
    {
        std::cout << "the value of the parameter x is  : " << x << std::endl;
    }
};

int main()
{
    DummyClass dObj;
    int x = 20;
    std::thread t1(&DummyClass::sampleFunClass, &dObj, x);
    t1.join();
    return 0;
}