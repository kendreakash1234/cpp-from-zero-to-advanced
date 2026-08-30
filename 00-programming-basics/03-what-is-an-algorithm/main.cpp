#include<iostream>

int main()
{
    int num{};
    std::cout<<"Enter the number"<<std::endl;
    std::cin>>num;
    if(num==0)
    {
        std::cout<<"Entered number is Zero"<<std::endl;
    }
    else if(num<0)
    {
        std::cout<<"Entered number is Negative"<<std::endl;
    }
    else
    {
        std::cout<<"Entered number is Positive"<<std::endl;
    }
    return 0;

}