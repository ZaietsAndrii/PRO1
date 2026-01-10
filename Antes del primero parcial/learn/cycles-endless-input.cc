    /// NOT CORRECT /////
// #include <iostream>
  
// int main()
// {
//     int n {};       // для ввода числа
//     // бесконечный цикл
//     while(true)
//     {
//         std::cout << "Enter a number: ";
//         std::cin >> n; // Вводим число
//         // если пользователь ввел 0, то выходим из цикла
//         if(n == 0) break; 
//         // иначе выводим квадрат числа
//         std::cout << n * n << std::endl;   
//     }
// }

#include <iostream>
 
int main()
{
    int numbers[] {1, 2, 3, 4, 5};
    // теперь n - ссылка на элемент массива
    for (auto& n : numbers)
    {
        n = n * n;
    }
    // смотрим результат (auto == var( in c#)), может определить тип явно int, ....
    for (auto n : numbers)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
}