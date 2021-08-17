#include <iostream>
#include <memory>

namespace example1
{
    class Resource
    {
    public:
        Resource()
        {
            std::cout << "Resource Aquired..\n";
        }

        ~Resource()
        {
            std::cout << "Resourced Destroyed..\n";
        }
    };

    void main()
    {
        std::unique_ptr<Resource> res1{new Resource{}};
        std::unique_ptr<Resource> res2{};

        std::cout << "Res1 is : " << static_cast<bool>(res1) ? "Not Null/n" : "Null/n";
        std::cout << "Res12 is : " << static_cast<bool>(res2) ? "Not Null/n" : "Null/n";

        //res2 = res1;

        res2 = std::move(res1);

        std::cout << "Res1 is : " << static_cast<bool>(res1) ? "Not Null\n" : "Null\n";
        std::cout << "Res12 is : " << static_cast<bool>(res2) ? "Not Null\n" : "Null\n";
    }
}

namespace CustomDelete
{
    struct Resource
    {
        Resource() { std::cout << "----Resource created---" << std::endl; }
        ~Resource() { std::cout << "----Resource destroyed---" << std::endl; }
    };

    struct deleter
    {
        void operator()() const
        {
            std::cout << "Custom deleter is used" << std::endl;
        }
    };

    void main()
    {
        std::unique_ptr<Resource, deleter> p1{new Resource()};
    }
}

int main()
{
    //example1::main();
    CustomDelete::main();
}