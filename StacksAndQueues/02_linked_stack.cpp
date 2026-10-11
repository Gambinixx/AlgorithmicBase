#include <iostream>
#include <vector>
#include "LinkedStack.h"

int main() {
    LinkedStack<int> stack;

    stack.push_five();
    std::cout << "Stack size: " << stack.get_size(); std::cout << "\n";

    std::cout << "Inside Stack: ";
    stack.print_stack(); std::cout << "\n";

    stack.pop();
    std::cout << "Stack after remove: ";
    stack.print_stack(); std::cout << "\n";

    stack.push(100);

    stack.push_five();
    std::cout << "Inside Stack: ";
    stack.print_stack();
    std::cout << "Stack size: " << stack.get_size() << "\n";

    std::vector<int> removed = stack.pop_five();
    std::cout << "Removed items list: ";
    // Для обычных vector<int> копирование почти ничего не стоит,
    // но для больших объектов позволяет сэкономить RAM и время на копирование
    for (const auto& item : removed) { 
        std::cout << item << " ";
    }
    std::cout << "\n";

    std::cout << "Stack after remove five items: ";
    stack.print_stack();
    std::cout << "Stack size: " << stack.get_size() << "\n";

    stack.push(900);
    std::cout << "Stack after push: ";
    stack.print_stack(); std::cout << "\n";
    std::cout << "Stack size: " << stack.get_size() << "\n";

    std::cout << "head hex-address: " << stack.get_top_ptr() << "\n";

    std::cout << "Get top of stack item: " << stack.peek() << "\n";

    // ~LinkedStack() деструктор автоматически вызывается и уничтожает стек
    return 0;
}