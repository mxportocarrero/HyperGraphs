//ejemplo de multithread
#include <iostream>
#include <thread>
#include <algorithm>

int main()
{
    std::vector<std::thread>workers;
    for(int i=0; i < 10; ++i)
    {
        workers.push_back(std::thread([i]()
        {
            std::cout<<"Hi from thread "<< i << "!\n";
        }));
    }
    std::cout<<"Hi from main!\n";
    std::for_each(workers.begin(),workers.end(),[](std::thread & th)
    {
        th.join();
    });
    return 0;
}
