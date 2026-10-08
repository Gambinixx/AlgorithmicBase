#pragma once
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Обход списка задом-наперед за O(N)
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

void delete_node(Node*& head, int key) {
    if (head == nullptr) return;
    // Первый сценарий
    if (head->data == key) {
        Node* temp = head; // хранит адрес текущего head
        head = head->next; // Сдвигаем head;
        if (head != nullptr) {
            head->prev = nullptr; // Очищаем указатель на предыдущий узел
        }

        delete temp;
        return;
    }

    // Второй сценарий
    Node* current = head;

    while (current != nullptr && current->data != key) {
        current = current->next;
    }

    if (current == nullptr) return;

    // Элементарная логика
    Node* next_node = current->next;
    Node* prev_node = current->prev;
    // Теперь связываем 
    prev_node->next = next_node;
    if (next_node != nullptr) {
        next_node->prev = prev_node;
    }

    delete current;
}

void insert_at_head(Node*& head, int val) {
    Node* new_node = new Node(val);

    if (head != nullptr) {
        head->prev = new_node; // Если список не пустой, пришиваем перед head;
    }

    new_node->next = head;

    head = new_node; // Объявляем новой стартовой точкой в main
}

void insert_at_tail(Node*& head, int val) {
    Node* current = head;
    Node* new_node = new Node(val);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = new_node;
    new_node->prev = current;
}

// Автоматический создатель двойного связного списка
void create_at_head(Node*& head, int counts) {   
    
    while (counts >= 1) {
        // Сделаем какую-то модификацию на каждом шаге
        insert_at_head(head, (counts * 10));

        counts--;
    }
};

void create_at_tail(Node*& head, int counts) {
    if (counts <= 0) return;

    int start_val = 60;

    for (int i = 0; i < counts; i++) {
        insert_at_tail(head, start_val);
        start_val += 10;
    }

};


// Печать списка вперёд (без изменений)
void print_list(Node* head) {
    Node* current = head;

    std::cout << "Doubly Linked List: ";
    while (current != nullptr) {
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Зачистка двусвязной памяти в Куче (без изменений)
void free_list(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
    std::cout << "Doubly linked list is cleared" << std::endl;
}