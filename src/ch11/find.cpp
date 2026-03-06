#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<functional>

template <typename Iter>
void print(Iter begin, Iter end)
{
    while(begin != end)
    {
        std::cout << "["<< *begin <<"]";
        begin++;
    }

    std::cout<<std::endl;
}

struct User
{
    std::string name;
    int level;

    User(std::string name, int level) : name(name), level(level) {}
    bool operator==(const User& user) const
    {
        if(name == user.name && level == user.level) return true;
        return false;
    }
};

class Party
{
private:
    std::vector<User> users_;
public:
    bool addUser(std::string name, int level)
    {
        User new_user(name, level);
        if(std::find(users_.begin(), users_.end(), new_user) != users_.end())
        {
            return false;
        }
        users_.push_back(new_user);
        return true;
    }

    bool canJoinDungeon()
    {
        return std::all_of(users_.begin(), users_.end(), [](User& user) { return user.level >= 15;});
    }

    bool canUseSpecialItem()
    {
        return std::any_of(users_.begin(), users_.end(), [](User& user) { return user.level >= 19;});
    }
};

int main()
{
    Party party;
    party.addUser("철수", 15);
    party.addUser("영희", 18);
    party.addUser("민수", 12);
    party.addUser("수빈", 19);

    std::cout<<std::boolalpha;
    std::cout<<"던전 입장 가능? "<<party.canJoinDungeon()<<std::endl;
    std::cout<<"특별 아이템 사용 가능? "<<party.canUseSpecialItem()<<std::endl; 

    return 0;
}