#include <iostream>
using namespace std;

template <typename T>
struct auto_ptr1
{
    auto_ptr1(T *ptr = nullptr) : m_ptr(ptr) {}
    ~auto_ptr1() { delete m_ptr; }

    //overload operator * and -> operator

    // T &operator*() { return *m_ptr; }
    // T *operator->() { return m_ptr; }

private:
    T *m_ptr;
};

class Resource
{
private:
    /* data */
public:
    Resource(/* args */);
    ~Resource();
};

Resource::Resource(/* args */)
{
    std::cout << "Resource is created..\n";
}

Resource::~Resource()
{
    std::cout << "Resource is destroyed .. \n";
}

int main()
{
    auto_ptr1<Resource> res{new Resource()};
    auto_ptr1<Resource> res2{res};
    return 0;
}