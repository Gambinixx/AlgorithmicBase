#pragma once

#include <iostream>
#include <cstddef>
#include <vector>

// Шаблонный чертеж узла
template <typename T>
struct Node {
    T data;
    Node* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedStack {
private:
    Node<T>* top_node;
    std::size_t size;

public:
    // Конструктор. Создаем голову списка, которая по-умолчанию указывает на nullptr
    LinkedStack() : top_node(nullptr), size(0) {}

    // Деструктор
    ~LinkedStack() {
        while (!is_empty()) {
            pop();
        }
    }

    // Вставка в начало связного списка. Я уже реализовывал логику вставки для связных списков, в виде функции insert_at_head и insert_at_tail
    void push(T val) {
        Node<T>* new_node = new Node<T>(val);

        new_node->next = top_node;
        
        top_node = new_node;
        
        size++;
    }

    // Срез вершины стека. Тут логика тоже знакомая, мне просто нужно удалить узел в начале списка (то есть голову).
    T pop() {
        if (is_empty()) return T{};

        Node<T>* temp = top_node;

        T top_value = top_node->data;

        top_node = top_node->next;

        delete temp;

        size--;

        return top_value;
    }

    // Везде где используем const справа от определение метода — это защита от изменения состояния объекта внутри метода
    T peek() const {
        if (is_empty()) return T{};

        return top_node->data;
    }

    bool is_empty() const {
        return top_node == nullptr;
    }

    std::size_t get_size() const {
        return size;
    }

    Node<T>* get_top_ptr() const {
        if (is_empty()) return nullptr;

        return top_node;
    }

    void push_five() {
        for (int i = 5; i >= 1; i--) {
            push(i * 100);
        }
    }

    void print_stack() const {
        Node<T>* next_node = top_node;

        while(next_node != nullptr) {
            std::cout << next_node->data << " ";

            next_node = next_node->next;
        }
        std::cout << std::endl;
    }

    // Убрать с вершины стека пять элементов и вернуть их в качестве списка
    std::vector<T> pop_five() {
        std::vector<T> removed;

        for (int i = 0; i < 5 && !is_empty(); i++) {
            removed.push_back(pop());
        }

        return removed;
    }
};