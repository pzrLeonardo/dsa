#include <iostream>
#include <string>
#include <array>

int main()
{
    int tamanhoCompras = 3;

    std::array <std::string, 5> compras = 
    {
        "parmesão",
        "gorgonzola",
        "tomate",
    };

    //1. Acesso direto
    std::cout << "Segundo item: " << compras.at(1) << '\n';

    //2. Inserção no início
    for (int i = tamanhoCompras; i > 0; i--)
    {
        compras.at(i) = compras.at(i - 1);
    }
    compras[0] = "tomilho";
    tamanhoCompras++;
    
    //3. Remoção no meio
    int i_remover = 2;
    for (int i = i_remover; i < tamanhoCompras - 1; i++)
    {
        compras[i] = compras[i + 1];
    }
    tamanhoCompras--;
    compras[3] = "";

    // Travessia (impressão do array todo) - o(n)
    std::cout << '\n';
    std::cout << "Itens da lista de compras: " << '\n';
    for (const std::string &item : compras)
    {
        std::cout << " - " << item << '\n';
    }

    return 0;
}