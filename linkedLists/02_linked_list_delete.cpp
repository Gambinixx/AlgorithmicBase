#include <iostream>
#include "linked_list_base.h"

/* delete_node перемещен в linked_list_base.h
void delete_node(Node*& head, int key) {

    if (head == nullptr) return; 

    // Сценарий 1: нужно удалить голову списка.
    if (head->data == key) {
        Node* temp = head; // сохраняем текущую
        head = head->next; // берем адрес следующего узла сдвигаем на head
        delete temp; // удаляем старый
        return;
    } 

    // Сценарий 2: Нужно найти узел где-то в списке
    Node* current = head;
    Node* prev = nullptr;

    // Пока не достигнем конца или не найдем значение
    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    // Второй предохранитель: Если уперлись в пустоту, выходим.
    if (current == nullptr) return;

    // Сшиваем предыдущий от current и следующий после него узлы.
    prev->next = current->next;

    delete current;
}
*/

int main() {
    Node* head = nullptr;

    insert_at_head(head, 40);
    insert_at_head(head, 30);
    insert_at_head(head, 20);
    insert_at_head(head, 10);

    std::cout << "Linked list: ";
    print_list(head);

    delete_node(head, 30);
    
    std::cout << "After first remove: ";
    print_list(head);

    delete_node(head, 10);
    std::cout << "After second remove: ";
    print_list(head);

    free_list(head);

    return 0;
}