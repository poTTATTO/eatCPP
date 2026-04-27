#include<iostream>
#include<mutex>
#include<thread>
#include<vector>


void worker(int& result, std::mutex& m)
{
    m.lock();
    for(int i=0; i<1000000; ++i)
    {
        result += 1;
        // m.unlock();
        std::cout<<result<<"\n";
    }
}

int main()
{
    int counter =0;
    std::mutex m;

    std::vector<std::thread> workers;

    for(int i=0; i<4; ++i)
    {
        workers.push_back(std::thread(worker, std::ref(counter), std::ref(m)));
    }

    for(int i=0; i<4; ++i)
    {
        workers[i].join();
    }

    std::cout<<"Counter 최종 값 : "<<counter<<std::endl;
}