#include<iostream>

class Employee
{

protected:
    std::string name_;
    int age_;
    std::string position_;
    int rank_;

public:
    Employee(std::string name, int age, std::string position, int rank)
        : name_(name), age_(age), position_(position), rank_(rank) {}
    
    Employee(const Employee& e)
    {
        name_ = e.name_;
        age_ = e.age_;
        position_ = e.position_;
        rank_ = rank_;
    }

    Employee(){}


    void printInfo(){
        std::cout<< name_ <<" (" <<position_<< " , " << age_ << ") == >"
            <<caculatePay()<<"만원"<<std::endl;
    }

    int caculatePay() { return 200 + rank_ * 50;}
};

class Manager : public Employee
{
    
private:
    int year_of_service_;

public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service)
        : Employee(name, age, position, rank), year_of_service_(year_of_service){}

    Manager(const Manager& manager)
        : Employee(manager.name_, manager.age_, manager.position_, manager.rank_)
        {
            year_of_service_ = manager.year_of_service_;
        }

    Manager() : Employee() {}

    int caculatePay() { return 200 + rank_ * 50 + 5 * year_of_service_;}
    void printInfo()
    {
        std::cout<<name_ <<" ("<<position_<<" , "<<age_ <<", "
            <<year_of_service_<<"년차) ==> "<<caculatePay()<<"만원"<<std::endl;
    }
};

class EmployeeList
{
private:
    int alloc_employee_; // 할당된 일반 직원 수 
    int alloc_manager_; // 할당된 매니저 수 
    int current_employee_; // 현재 직원 수 
    int current_manager_;

    Employee** employee_list_;
    Manager** manager_list_;

public:
    EmployeeList(int alloc_employee, int alloc_manager) : alloc_employee_(alloc_employee), alloc_manager_(alloc_manager)
    {
        employee_list_ = new Employee*[alloc_employee];
        manager_list_ = new Manager*[alloc_manager_];
        current_employee_ = 0;
        current_manager_ = 0;
    }

    void addEmployee(Employee* employee)
    {
        if(current_employee_ >= alloc_employee_)
        {
            std::cout<<"재할당 합니데이"<<std::endl;
            std::cout<<"현재 공간 : "<<alloc_employee_<<std::endl;
            Employee** tmp = new Employee*[2 * alloc_employee_];
            for(int i=0; i<current_employee_; ++i)
            {
                tmp[i] = employee_list_[i];
            }
            delete[] employee_list_;
            employee_list_ = tmp;
            alloc_employee_ = 2 * alloc_employee_;
            std::cout<<"새롭게 할당된 공간 : "<<alloc_employee_<<std::endl;
        }
        employee_list_[current_employee_] = employee;
        current_employee_++;
    }

    void addManager(Manager* manager)
    {

        if(current_manager_ >= alloc_employee_)
        {
            std::cout<<"재할당 합니데이"<<std::endl;
            std::cout<<"현재 공간 : "<<alloc_manager_<<std::endl;
            Manager** tmp = new Manager*[2 * alloc_manager_];
            for(int i=0; i<current_manager_; ++i)
            {
                tmp[i] = manager_list_[i];
            }
            delete[] manager_list_;
            manager_list_ = tmp;
            alloc_employee_ = 2 * alloc_employee_;
            std::cout<<"새롭게 할당된 공간 : "<<alloc_manager_<<std::endl;
        }
        manager_list_[current_manager_] = manager;
        current_manager_++;
    }

    int current_employee_sum() { return current_employee_ + current_manager_;}

    void printEmployeeInfo()
    {
        int total_pay = 0;
        for (int i=0; i<current_employee_; ++i)
        {
            employee_list_[i]->printInfo();
            total_pay += employee_list_[i]->caculatePay();
        }

        for(int i=0; i<current_manager_; ++i)
        {
            manager_list_[i]->printInfo();
            total_pay+=manager_list_[i]->caculatePay();
        }

        std::cout<<"총 비용 : "<<total_pay <<"만원"<<std::endl;
    }

    ~EmployeeList()
    {
        for(int i=0; i<current_employee_; ++i)
        {
            delete employee_list_[i];
        }
        for(int i=0; i<current_manager_; ++i)
        {
            delete manager_list_[i];
        }

        delete[] employee_list_;
        delete[] manager_list_;
    }

};

int main() {
    EmployeeList emp_list(4,3);
    emp_list.addEmployee(new Employee("노홍철", 34, "평사원", 1));
    emp_list.addEmployee(new Employee("하하", 34, "평사원", 1));
    emp_list.addManager(new Manager("유재석", 41, "부장", 7,12));
    emp_list.addManager(new Manager("정준하", 43, "과장", 4,15));
    emp_list.addManager(new Manager("박명수", 43, "차장", 5,13));
    emp_list.addEmployee(new Employee("정형돈", 36, "대리", 2));
    emp_list.addEmployee(new Employee("길", 36, "인턴", -2));
    // emp_list.addEmployee(new Employee("닝닝", 32, "평사원", 3));
    emp_list.printEmployeeInfo();
return 0;
}