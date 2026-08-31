#include<iostream>

int main()
{
    int balance{1000};
    std::cout<<balance<<std::endl;
    balance += 500;
    std::cout<<balance<<std::endl;
    balance -= 300;
    std::cout<<balance<<std::endl;

    return 0;
}