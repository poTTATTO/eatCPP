#include<string>
#include<iostream>
#include<set>

template <typename T, typename C>
void print_set(std::set<T, C>& s)
{
    std::cout<<"[ ";
    for(const auto& elem : s)
    {
        std::cout<< elem <<" "<<std::endl;
    }
}

class Todo
{
private:
    int priority_;
    std::string desc_;
public:
    Todo(int p, std::string d) : priority_(p), desc_(d) {}

    friend struct TodoCmp;
    friend std::ostream& operator<<(std::ostream& os, const Todo& t);
};

struct TodoCmp
{
    bool operator()(const Todo& t1, const Todo& t2) const
    {
        if(t1.priority_ == t2.priority_)
        {
            return t1.desc_ < t2.desc_;
        }
        return t1.priority_ > t2.priority_;
    }
};

std::ostream& operator<<(std::ostream& os, const Todo& t)
{
    os<< "[ 중요도 : "<<t.priority_ <<"] " <<t.desc_;
    return os;
}