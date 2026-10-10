// stack.h
#pragma once

#include <iostream>
#include <vector>
#include <cstddef>

// Немного модифицируем стек, сделав его универсальным для разных типов данных при помощи шаблонного параметра T
template <typename T>
class ArrayStack {
private:
    std::vector<T> storage;

public:
    void push(T val) { // Закидываем в конец (на вершину)
        storage.push_back(val);
    }

    std::size_t get_size() const {
        return storage.size();
    }

    T peek() const {
        if (is_empty()) return T{};
        return storage.back();
    }

    T pop() { // Удаляем с вершины и возвращаем удаленный элемент
        if (is_empty()) return T{};

        T top_item = storage.back();
        storage.pop_back();
        return top_item;
    }

    const T* get_ptr() const { // const нужен чтобы нельзя было изменить стек через полученный указатель
        return storage.data();
    }

    void print_stack() const {
        for (std::size_t i = 0; i < storage.size(); ++i) {
            std::cout << storage[i] << " ";
        }
    }

    bool is_empty() const {
        return storage.empty();
    }
};