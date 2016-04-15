//ejemplo de multithread
#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

int main()
{
    vector <thread> workers;
    for(int i=0; i < 100; ++i)
    {
        workers.push_back(thread([i]()
        {
            cout<<"Hi from thread " << i << "!\n";
        }));
    }
    cout<<"Hi from main!\n";
    for_each(workers.begin(),workers.end(),[](thread & th)
    {
        th.join();
    });
    return 0;
}
