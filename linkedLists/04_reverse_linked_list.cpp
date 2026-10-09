#include <iostream>
#include "linked_list_base.h"

// Разворот списка на месте за O(n) по количеству операций, и O(1) по памяти
void reverse_list(Node*& head) {
    Node* current = head;
    Node* reverse = nullptr;
    Node* next_node = nullptr;

    while (current != nullptr) {
        next_node = current->next;

        current->next = reverse; // Разворачиваем на reverse

        reverse = current; // Накапливаем reverse список, потом приклеим его к head
        current = next_node;
    }

    head = reverse;
}




int main() {
    Node* head = nullptr;
    
    for (int i = 5; i >= 1; i--) {
        insert_at_head(head, (i * 10));
    }

    std::cout << "Original List: ";
    print_list(head);

    // Запуск разворота
    reverse_list(head);

    std::cout << "Reversed List: ";
    print_list(head); // Reversed List: 50 -> 40 -> 30 -> 20 -> 10 -> nullptr

    free_list(head);
    return 0;
}