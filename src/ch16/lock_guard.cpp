#include<iostream>
#include<mutex>
#include<thread>
#include<vector>


void worker(int& result, std::mutex& m)
{
    for(int i=0; i<1000000; ++i)
    {
        //lock 생성 시에 m.lock()을 실행한다고 보면된다. 
        std::lock_guard<std::mutex> lock(m);
        result += 1;
        
        //scope를 빠져 나가면 lock이 소멸되면서 
        // m 을 알아서  unlock한다. 
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