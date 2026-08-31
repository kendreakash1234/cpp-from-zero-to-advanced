#include<iostream>

int main()
{
    int price1{},quantity1{},result1{},price2{},quantity2{},result2{};
    std::cout<<"Enter the price of first product : ";
    std::cin>>price1;
    std::cout<<"Enter the quantity of first product : ";
    std::cin>>quantity1;
    std::cout<<"Enter the price of second product : ";
    std::cin>>price2;
    std::cout<<"Enter the quantity of second product : ";
    std::cin>>quantity2;

    result1 = price1*quantity1;
    result2 = price2*quantity2;

    std::cout<<"Final product of first product : "<<result1<<std::endl;
    std::cout<<"Final product of second product : "<<result2<<std::endl;

    return 0;
}