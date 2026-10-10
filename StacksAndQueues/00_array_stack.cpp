#include <iostream>
#include <vector>

using namespace std;

// Создаем стек на базе контейнера vector чтобы иметь возможность динамически изменять размер стека.
class ArrayStack {// Разница между struct и class в том, что у класса есть зона private к которой доступ у нас будет только через методы класса
private:
    vector<int> storage; // Никто не сможет изменить наш стек напрямую, как если бы это был объект struct

public:
    void push(int val) { // Закидываем в конец (на вершину)
        storage.push_back(val);
    }

    int get_size() const {
        return storage.size();
    }

    int peek() const {
        if (is_empty()) return -1;
        return storage.back();
    }

    int pop() { // Удаляем с вершины и возвращаем удаленный элемент
        if (is_empty()) return -1;

        int top_item = storage.back();
        storage.pop_back();
        return top_item;
    }

    const int* get_ptr() const { // const нужен чтобы нельзя было изменить стек через полученный указатель
        return storage.data();
    }

    void print_stack() const {
        for (size_t i = 0; i < storage.size(); ++i) {
            cout << storage[i] << " ";
        }
    }

    bool is_empty() const {
        return storage.empty();
    }
};


int main() {
    ArrayStack stack;

    for (int i = 1; i <= 5; i++) {
        stack.push(i * 10);
    }

    cout << "Stack size: " << stack.get_size() << endl;

    cout << "Stack sequence: "; stack.print_stack(); cout << endl;

    cout << "Top item: " << stack.peek() << endl;

    cout << "stack hex-address: " << stack.get_ptr() << endl;

    cout << "Remove top item: " << stack.pop() << endl;

    cout << "After remove: "; stack.print_stack(); cout << endl;

    return 0;
}