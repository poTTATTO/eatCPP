#include<iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<stdexcept>
#include<cstring>

class Complex
{

private:
    double real_;
    double img_;
    double getNumber(const char* number, int from, int to);

public:
    Complex(double real, double img);
    Complex(const char* number);
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex& operator=(const Complex& c);
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator/=(const Complex& c);
    Complex& operator*=(const Complex& c);

    friend Complex operator+(const Complex& a, const Complex& b);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    void print() const;
};

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os<<"( "<<  c.real_ << " , "<<c.img_ <<")";
    return os;
}

Complex operator+(const Complex& a, const Complex& b)
{   
    Complex tmp(a.real_ + b.real_ , a.img_ + b.img_);
    return tmp;
}
double Complex::getNumber(const char* number, int from, int to)
{
    if(!number)
        throw std::runtime_error("string error");
    if(from > to)
        throw std::runtime_error("range errror");
    
    bool minus(false);
    if(number[from] == '-')
    {
        minus = true;
        from++;
    }
    else if(number[from] == '+')
        from++;
    
    double num(0.0);
    double decimal(1.0);
    int div_cnt(0);
    bool is_integer(true);

    for(int i=from; i <= to; i++)
    {
        if(isdigit(number[i]))
        {
            num *= 10.0;
            num += (number[i] - '0');

            if(!is_integer)
                div_cnt++;
        }else if(number[i] == '.')
        {
            if(!is_integer)
                throw std::runtime_error(". 두개 찍힘");
            is_integer = false;
        }
        else
            break;
    }
    
    num /= pow(10, div_cnt);

    return !minus ? num : -num;
}

Complex::Complex(const char* number)
{
    if(!number)
        throw std::runtime_error("param error");
    int from = 0;
    int to = strlen(number) - 1;
    int pos_i = -1;
    for(int i = from; i <= to; i++)
    {
        if(number[i] == 'i')
            pos_i = i;
    }
    if(pos_i == -1)
    {
        real_ = getNumber(number, from, to);
    }
    else
    {
        real_ = getNumber(number, from, pos_i - 1);
        img_ = getNumber(number, pos_i + 1, to);
    

        if(pos_i >= 1 && number[pos_i - 1] == '-')
            img_ *= -1.0;
    }
}
Complex& Complex::operator/=(const Complex& c)
{
    *this = *this / c;
    return *this;
}
Complex& Complex::operator*=(const Complex& c)
{
    *this = *this * c;
    return *this;
}
Complex& Complex::operator-=(const Complex& c)
{
    this ->real_ -= c.real_;
    this ->img_ -= c.img_;

    return *this;    
}
Complex& Complex::operator+=(const Complex& c)
{
    this->real_ += c.real_;
    this->img_ += c.img_;

    return *this;
}
void Complex::print() const
{
    if(img_ != 0){
        std::cout<< real_ << std::showpos << img_ <<"i"<<std::noshowpos<<std::endl;
    }else{
        std::cout<< real_ << std::endl;
    }
}
Complex::Complex(double real, double img) : real_(real), img_(img)
{
}

Complex Complex::operator+(const Complex& c) const
{
    double real = real_ + c.real_;
    double img = img_ + c.img_;

    return Complex(real, img);
}

Complex Complex::operator-(const Complex& c) const
{
    double real = real_ +  -c.real_;
    double img = img_ +  -c.img_;

    return Complex(real, img);
}

Complex Complex::operator*(const Complex& c) const
{
    double real = (real_ * c.real_) - (img_ * c.img_);
    double img = (real_ * c.img_) + (c.real_ * img_);
    return Complex(real, img);
}

Complex Complex::operator/(const Complex& c) const
{
    if( c.real_ == 0 && c.img_ == 0){
        std::cout<<"분모가 0이 될 수 없음, 분자 반환"<<std::endl;
        return *this;
    }

    double real = (real_ * c.real_ + img_ * c.img_) / ((c.real_* c.real_) + (c.img_ * c.img_));
    double img = (c.real_ * img_ - real_ * c.img_) / ((c.real_ * c.real_) + (c.img_ * c.img_));

    return Complex(real, img);
}

Complex& Complex::operator=(const Complex& c)
{
    real_  = c.real_;
    img_ = c.img_;
    return *this;
}

int main()
{
    Complex s1("-1.234-i123.34");
    std::cout<<s1<<std::endl;
    return 0;
}


