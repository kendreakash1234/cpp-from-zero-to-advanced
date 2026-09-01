#include<iostream>

int main()
{
    int num1{}, num2{};
    num1=10;
    num2=20;
    int result{};
    
    result = num1+num2;

    std::cout<<result<<'\n';

    num1 = 30;

    result = num1+num2;

    std::cout<<result<<'\n';

    return 0;

}