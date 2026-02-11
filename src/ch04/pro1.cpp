#include<iostream>

class Date{
    int year;
    int month;
    int day;
    int day_array[13] = {0,31,28,31,30,31,30, 31,31,30,31,30,31};
public:
    void setDate(int year, int month, int date);
    void addDay(int inc);
    void addMonth(int inc);
    void addYear(int inc);
    void showDate();
    int Date::getCurrentMonthTotalDays(int year, int month);
    Date();
};

Date::Date(){
    year = 0;
    month = 0;
    day = 0;
}
void Date::setDate(int year, int month, int day){
    if(!(month >= 1 && month <= 12)){
        std::cout<<"월 잘못"<<std::endl;
        return;
    }
    if(!(day >= 1 && day <= 31)){
        std::cout<<"날짜 잘못"<<std::endl;
        return;
    }
    this->year = year;
    this->month = month;
    this->day = day;
}

int Date::getCurrentMonthTotalDays(int year, int month){
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if(leap && month == 2) return 29;
    else{
        return day_array[month];
    }
}

void Date::addDay(int inc){
    int d = getCurrentMonthTotalDays(year, month);
    if(day + inc <= d){
        day += inc;
    }else{
        month += (day + inc) / d;
        if(month > 12){
            year += month / 12;
            month = month % 12;
        }
        day = (day + inc) % d;
    }

}

void Date::addMonth(int inc){
    year += (month + inc) / 12;
    month = (month + inc) % 12;
}

void Date::addYear(int inc){
    year += inc;
}

void Date::showDate(){
    std::cout<<year<<"/"<<month<<"/"<<day<<std::endl;
}

int main(){
    Date date;

    date.setDate(2026,12,30);
    date.addMonth(13);

    date.showDate();

    return 0;

}