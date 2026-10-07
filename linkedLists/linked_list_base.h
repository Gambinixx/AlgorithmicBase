#pragma once // Предохранитель от двойного импорта + защита от падения при попытке создать уже существующий чертеж структуры (Node в нашем случае) в памяти.
#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void delete_node(Node*& head, int key) {
    if (head == nullptr) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) return;

    prev->next = current->next;

    delete current;
}

void insert_at_head(Node*& head, int val) {
    Node* new_node = new Node(val);

    new_node->next = head;

    head = new_node;
}

void insert_at_tail(Node*& head, int val) {
    Node* new_node = new Node(val);
    Node* current = head;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    while (current->next != nullptr) {
        current = current->next;
    }
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

    if (head == nullptr) return;

    while (current != nullptr) {
        next_node = current->next;
        delete current;
        current = next_node;
    }
    std::cout << "linked list is cleared" << std::endl;
}