#include <iostream>
#include <functional>
using namespace std;

void foo(int x, int y)
{
    cout << "Hello World!!" << std::endl;
}

int main()
{
    std::function<void(int, int)> pfun1{};
    pfun1 = &foo;
    std::cout << foo << std::endl;
    auto pfun{&foo};
    pfun(2, 3);
    pfun1(4, 5);
}