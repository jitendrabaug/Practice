#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <functional>

namespace joinlist
{
    class WorkerThread
    {
    public:
        void operator()()
        {
            std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
        }
    };

    void main()
    {

        std::vector<std::thread> threadList;

        for (size_t i = 0; i < 10; i++)
        {
            threadList.push_back(std::thread(WorkerThread()));
        }

        std::cout << "wait for all the worker thread to finish" << std::endl;

        for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
        std::cout << "Exiting from Main Thread" << std::endl;
    }

}

int main()
{
    joinlist::main();
}