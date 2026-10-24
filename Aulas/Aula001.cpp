#include <iostream>
#include <queue>

int main ()
{
    std::queue<int> fila;
    
    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);
    fila.push(5);
    fila.push(6);

    std::cout << "primeiro da fila: " << fila.front() << "\n";
    std::cout << "Quantidade de elementos: " << fila.size() << "\n";

    std::cout << "Repeticao com fila: " << "\n";

    while (!fila.empty())
    {
        std::cout << "elemento: " << fila.front() << "\n";
        fila.pop();
    }

}
