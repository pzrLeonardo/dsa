/*
Exercício: 

Usando stack, crie um algoritmo que verifique se uma expressão é ou não balanceada.

Exemplo:
(a + b) -> balanceada
(a + b)) -> não balanceada
((a + b) * c) -> balanceada

*/

#include <iostream>
#include <stack>
#include <string>

// Função que verifica se a expressão está balanceada
bool estaBalanceada(std::string expressao) {
    std::stack<char> pilha;

    for (char c : expressao) {
        // Se for abertura, joga na pilha
        if (c == '(' || c == '[' || c == '{') {
            pilha.push(c);
        } 
        // Se for fechamento, checa as regras
        else if (c == ')' || c == ']' || c == '}') {
            // Erro 1: Fechamento sem ter nenhuma abertura na pilha
            if (pilha.empty()) {
                return false;
            }

            char topo = pilha.top();
            
            // Erro 2: O fechamento atual não combina com a última abertura
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                return false;
            }

            // Se combinou direitinho, tira da pilha
            pilha.pop();
        }
    }

    // Se a pilha terminar vazia, está certa. Se sobrou algo, está errada.
    return pilha.empty();
}

int main() {
    // Casos de teste
    std::string ex1 = "{(a + b)}"; // Correto
    std::string ex2 = "{(a + b))}"; // Errado

    std::cout << "Expressao 1: " << (estaBalanceada(ex1) ? "Balanceada" : "Correto") << std::endl;
    std::cout << "Expressao 2: " << (estaBalanceada(ex2) ? "Balanceada" : "Errado") << std::endl;

    return 0;
}
