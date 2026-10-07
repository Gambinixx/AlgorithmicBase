#include <iostream>

struct Node {
    // Чертеж
    int data;
    Node* next;

    // Конструктор. Компактная запись.
    Node(int val) : data(val), next(nullptr) {}
};

// Работаем с переменной указателем, поэтому нужен оригинал, а не локальная копия
void insert_at_head(Node*& head, int val) {
    Node* new_node = new Node(val);

    new_node->next = head; // Сохраняем адрес следующего узла
    head = new_node; // текущий узел ставим вначале списка
}

void insert_at_tail(Node*& head, int val) {
    Node* new_node = new Node(val);
    Node* current = head;

    // Проверяем пустой ли список
    if (head == nullptr) {
        head = new_node; // ставим во главе
        return;
    }

    // Проходим по всему списку пока не наткнемся на nullptr
    while (current->next != nullptr) {
        current = current->next;
    }
    // В конце пришиваем хвост
    current->next = new_node;
}

void print_list(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void free_list(Node* head) {
    Node* current = head;
    Node* next_node;
    while (current != nullptr) {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    std::cout << "Linked list cleared";
}

int main() {
    Node* head = nullptr; // наш указатель который мы будем изменять абстракцией ниже, в insert_at_head и insert_at_tail

    insert_at_head(head, 30);
    insert_at_head(head, 20);
    insert_at_head(head, 10);

    insert_at_tail(head, 40);

    std::cout << "Linked list: " << std::endl;
    print_list(head);

    free_list(head);

    return 0;
}
