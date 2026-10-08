#include <iostream>
#include "doubly_linked_list_base.h"

// Перемещен в doubly_linked_list_base.h
/*
void print_list_reverse(Node* head) {
    if (head == nullptr) return;

    Node* current = head;

    // Находим хвост
    while (current->next != nullptr) {
        current = current->next;
    }

    // Запускаем цикл движения назад через указатели prev
    std::cout << "Reverse list: nullptr";
    while (current != nullptr) {
        std::cout << " <-> " << current->data;
        current = current->prev;
    }
    std::cout << std::endl;
}
*/

int main() {
    Node* head = nullptr;

    int node_at_head = 5;
    int node_at_tail = 5;

    // Модификация шага: i * 10
    create_at_head(head, node_at_head);
    print_list(head);

    create_at_tail(head, node_at_tail);
    print_list(head);

    // Тестируем обратный ход
    print_list_reverse(head);

    delete_node(head, 30);
    delete_node(head, 10);
    print_list(head);

    print_list_reverse(head);

    free_list(head);
    return 0;
}