#include <iostream>
#include <limits>

// Reusable logic: is x an even number?
bool isEven(int x)
{
    return (x % 2 == 0);
}

int main()
{
    int N{}, sum{}, total_count{}, even_count{};
    double average{};
    int max = std::numeric_limits<int>::min();  // start LOWEST so any x updates it
    int min = std::numeric_limits<int>::max();  // start HIGHEST so any x updates it

    std::cout << "Enter the number : ";
    if (!(std::cin >> N))
    {
        std::cerr << "Invalid input: Expected integer\n";
        return 1;
    }

    // Sentinel loop: read-first, process, read-again. 0 ends input.
    while (N != 0)
    {
        sum += N;
        if (isEven(N))
        {
            even_count++;
        }
        total_count++;
        if (max < N)
        {
            max = N;
        }
        if (min > N)
        {
            min = N;
        }

        std::cout << "Enter the number and to exit press 0 : ";
        if (!(std::cin >> N))
        {
            std::cerr << "Invalid input: Expected integer\n";
            return 1;
        }
    }

    if (total_count <= 0)
    {
        std::cerr << "count should not be zero\n";
        return 1;
    }

    average = static_cast<double>(sum) / total_count;

    std::cout << "Sum = " << sum << '\n';
    std::cout << "min = " << min << '\n';
    std::cout << "max = " << max << '\n';
    std::cout << "total count = " << total_count << '\n';
    std::cout << "even count = " << even_count << '\n';
    std::cout << "average = " << average << '\n';

    return 0;
}
