#include<iostream>

int main()
{
    // int temperature{};
    // std::cout<<"Enter the temperature : ";
    // if(!(std::cin>>temperature)){
    //     std::cout<<"Entered value is ot integer\n";
    //     return -1;
    // }
    // if(temperature>30)
    // {
    //     std::cout<<"Hot\n";
    // }else
    // {
    //     std::cout<<"Not hot\n";
    // }

    int number{};
    std::cout<<"Enter the number : ";
    if(!(std::cin>>number)){
        std::cout<<"Entered number is not integer\n";
        return -1;
    }
    if(number>0)
    {
        std::cout<<"Positive\n";
    }else
    {
        std::cout<<"Zero or negative\n";
    }
    return 0;
}