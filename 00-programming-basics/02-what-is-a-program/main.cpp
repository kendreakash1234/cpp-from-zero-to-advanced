#include <iostream>
#include <string>

int main()
{
    //A program that displays information about a person.
    std::string name{};
    int age{};
    std::string role{};

    std::cout<<"Enter the name of user : ";
    getline(std::cin, name);
    std::cout<<"Enter the age of user : ";
    std::cin>>age;
    
    std::cin.ignore();// TODO: Handle invalid input after learning input validation.

    std::cout<<"Enter the role of user : ";
    std::getline(std::cin, role);

    std::cout<<"Name : "<<name<<'\n';
    std::cout<<"Age : "<<age<<'\n';
    std::cout<<"Role : "<<role<<'\n';

    return 0;
}