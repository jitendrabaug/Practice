#include <iostream>
#include <thread>

namespace thread1
{

    struct createThread
    {
        void operator()()
        {
            for (int i = 0; i < 100; i++)
                std::cout << "called in functor\n";
        }
    };
    void fun1()
    {
        std::cout << "called the thread using function object !!!" << std::endl;
    }

    void main()
    {
        std::thread t1(fun1);

        std::thread t2((createThread()));
        for (int i = 0; i < 100; i++)
            std::cout << "called in main thread \n";

        std::thread t3([]()
                       { std::cout << "This thread is created using lambda\n"; });

        std::cout << "t1 = " << t1.get_id() << " t2 = " << t2.get_id() << " t3 = " << t3.get_id() << "\n";

        t1.join();
        t2.join();
        t3.join();
        std::cout << "The main is terminated..." << std::endl;
    }
}

namespace threadId
{
    void thread_function()
    {
        std::cout << "Inside Thread :: ID  = " << std::this_thread::get_id() << std::endl;
    }

    void main()
    {
        std::thread threadObj1(thread_function);
        std::thread threadObj2(thread_function);

        if (threadObj1.get_id() != threadObj2.get_id())
            std::cout << "Both Threads have different IDs" << std::endl;

        std::cout << "From Main Thread :: ID of Thread 1 = " << threadObj1.get_id() << std::endl;
        std::cout << "From Main Thread :: ID of Thread 2 = " << threadObj2.get_id() << std::endl;

        threadObj1.join();
        threadObj2.join();
    }
}

int main()
{

    //thread1::main();

    threadId::main();
}