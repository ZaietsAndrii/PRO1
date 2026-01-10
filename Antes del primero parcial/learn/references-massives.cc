#include <iostream>
 
int main()
{
    int numbers[] {1, 2, 3, 4, 5};
    // меняем число на его квадрат
    for (auto n : numbers)
    {
        n = n * n;
    }
    // смотрим результат
    for (auto n : numbers)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
}
 

    // Перебор многомерного массива
int main()
{
    const int rows = 3, columns = 2;
    int numbers[rows][columns]  { {1, 2}, {3, 4}, {5, 6} };
     
    for(auto &subnumbers : numbers)
    {
        for(int number : subnumbers)
        {
            std::cout << number << "\t";
        }
        std::cout << std::endl;
    }
}