#include <iostream>

// TOPIC: Breaking a problem into smaller sub-problems (decomposition).
// Big goal 1: area + perimeter of a rectangle.
// Big goal 2: check whether a number is prime.
// Each sub-problem below is solved by ONE small function.

// Sub-problem: area of a rectangle
double calcArea(double length, double width)
{
    return length * width;
}

// Sub-problem: perimeter of a rectangle
double calcPerimeter(double length, double width)
{
    return 2 * (length + width);
}

// Sub-problem: read one number from the user.
// Returns -1 on invalid input (rejected later by validation).
double getUserInput()
{
    double value;
    if (!(std::cin >> value))
    {
        std::cout << "Invalid input: not a number\n";
        std::cin.clear();
        return -1;
    }
    return value;
}

// Sub-problem: is a dimension valid (strictly positive)?
bool isValidDimension(double num)
{
    return num > 0;
}

// Sub-problem: is x prime?
bool isPrime(int x)
{
    if (x < 2)
        return false;
    if (x == 2 || x == 3)
        return true;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    // --- Sub-problem group A: rectangle ---
    std::cout << "Enter length of Rectangle : ";
    double length = getUserInput();
    if (!isValidDimension(length))
    {
        std::cout << "length must be greater than zero\n";
        return -1;
    }

    std::cout << "Enter width of Rectangle : ";
    double width = getUserInput();
    if (!isValidDimension(width))
    {
        std::cout << "width must be greater than zero\n";
        return -1;
    }

    std::cout << "Area of rectangle is " << calcArea(length, width) << '\n';
    std::cout << "Perimeter of rectangle is " << calcPerimeter(length, width) << '\n';

    // --- Sub-problem group B: prime check ---
    std::cout << "Enter the number to check it is prime or not : ";
    int number;
    if (!(std::cin >> number))
    {
        std::cout << "Invalid input: not an integer\n";
        std::cin.clear();
        return -1;
    }

    if (isPrime(number))
        std::cout << number << " is prime number\n";
    else
        std::cout << number << " is not a prime number\n";

    return 0;
}