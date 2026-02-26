#include<iostream>
#include<set>
#include<string>

template <typename T>
void print_set(std::set<T>& s)
{
    std::cout<<"[ ";
    for(const auto& elem : s)
    {
        std::cout<<elem<< " "<<std::endl;
    }
    std::cout<<" ] "<<std::endl;
};

class Todo
{
private:
    int priority_;
    std::string job_desc_;

public:
    Todo(int priority, std::string job_desc) : priority_(priority) , job_desc_(job_desc) {}

    bool operator<(const Todo& t) const
    {
        if(priority_ == t.priority_)
        {
            return job_desc_ < t.job_desc_;
        }

        return priority_ > t.priority_;
    }

    friend std::ostream& operator<<(std::ostream& os, const Todo& t); 
};

std::ostream& operator<<(std::ostream& os, const Todo& t)
{
    os<< "[ " << t.priority_ << " ] " << t.job_desc_;
    return os;
}

int main()
{
    std::set<Todo> todos;

    todos.insert(Todo(1, "농구하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기")); 

    print_set(todos);

    std::cout<<"-----------"<<std::endl;
    std::cout<<"숙제를 끝냈다면 !"<<std::endl;

    todos.erase(todos.find(Todo(2,"수학 숙제 하기")));
    print_set(todos);
    return 0;
}