#include <iostream>

using namespace std;

template <typename T>
class auto_ptr3
{
private:
    T *m_ptr;

public:
    auto_ptr3(T *ptr = nullptr);
    ~auto_ptr3();

    auto_ptr3(const auto_ptr3 &obj)
    {
        m_ptr = new T;
        *m_ptr = *obj.m_ptr;
    }

    auto_ptr3 &operator=(const auto_ptr3 &obj)
    {
        if (this == &obj)
            return *this;

        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *obj.m_ptr;
        return *this;
    }

    auto_ptr3(auto_ptr3 &&obj) : m_ptr(obj.m_ptr)
    {
        std::cout << "I am move constructor..\n";
        obj.m_ptr = nullptr;
    }

    auto_ptr3 &operator=(auto_ptr3 &&obj)
    {
        if (this == &obj)
            return *this;

        delete m_ptr;

        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;
        std::cout << "I am move assignment operator..\n";
        return *this;
    }

    T &operator*() { return *m_ptr; }
    T *operator->() { return m_ptr; }
};

template <typename T>
auto_ptr3<T>::auto_ptr3(T *ptr) : m_ptr(ptr)
{
    std::cout << "auto_ptr object is created..\n";
}

template <typename T>
auto_ptr3<T>::~auto_ptr3()
{
    std::cout << "auto_ptr object is destroyed..\n";
}

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
    std::cout << "Resource is created...\n";
}

Resource::~Resource()
{
    std::cout << "Resource is Destroyed .. \n";
}

auto_ptr3<Resource> generateResource()
{
    auto_ptr3<Resource> res{new Resource};
    return res;
}

int main(int argc, char const *argv[])
{
    std::unique_ptr<Resource> res{};
    auto_ptr3<Resource> res = generateResource();
    return 0;
}
