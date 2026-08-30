#include<iostream>

int main()
{
    double price{};
    int quantity{};
    double tax{};
    double finalPrice{};

    std::cout<<"Enter the price of item : ";
    std::cin>>price;
    std::cout<<"Enter the quantity  : ";
    std::cin>>quantity;
    std::cout<<"Enter the tax : ";
    std::cin>>tax;

    finalPrice = (price*quantity)+(price*quantity*tax/100);

    std::cout<<"Final price is "<<finalPrice<<std::endl;

    return 0;

}