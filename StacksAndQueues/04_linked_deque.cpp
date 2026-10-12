#include <iostream>
#include <cstddef>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class LinkedDeque {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t size;

public:
    LinkedDeque() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedDeque() {
        while (!is_empty()) {
            pop_front();
        }
    }

    void push_front(T val) {
        Node<T>* new_node = new Node<T>(val);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    void push_back(T val) {
        Node<T>* new_node = new Node<T>(val);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    T pop_front() {
        if (is_empty()) return T{};

        Node<T>* temp = head;
        T head_value = head->data;

        head = head->next; // Не забываем сдвинуть голову.

        if (head == nullptr)
            {tail = nullptr;} // если голова пуста, то обнуляем хвост
        else 
            {head->prev = nullptr;} // если не пуста то обнуляем указатель prev
        
        delete temp;
        size--;
        return head_value;
    }

    T pop_back() {
        if (is_empty()) return T{};
        Node<T>* temp = tail;

        T tail_value = tail->data;

        tail = tail->prev;

        if (tail == nullptr)
            {head = nullptr;} // Список опустел
        else
            {tail->next = nullptr;} // текущий хвост не пустой, ставим впереди нули.
        
        delete temp;
        size--;
        return tail_value;
    }

    Node<T>* get_top_ptr() const {
        if (is_empty()) return nullptr;
        return head;
    }
    
    Node<T>* get_down_ptr() const {
        if (is_empty()) return nullptr;
        return tail;
    }

    T peek_front() const {
        if (is_empty()) return T{};
        return head->data;
    }

    T peek_back() const {
        if (is_empty()) return T{};
        return tail->data;
    }

    bool is_empty() const { // теперь при вызове этого метода внутри другого константного метода, проблем с компилятором не возникнет
        return head == nullptr;
    }
    
    std::size_t get_size() const {
        return size;
    }
};
    
int main() {
    LinkedDeque<int> deque;

    deque.pop_front();
    deque.pop_back();

    // Крутим дек во все стороны
    deque.push_back(20);  //  20
    deque.push_front(10); // 10 <-> 20
    deque.push_back(30);  // 10 <-> 20 <-> 30

    std::cout << "Front: " << deque.peek_front() << " (Expected: 10)" << std::endl;
    std::cout << "Back: " << deque.peek_back() << " (Expected: 30)" << std::endl;

    std::cout << "Pop Back: " << deque.pop_back() << " (Expected: 30)" << std::endl;
    std::cout << "New Back: " << deque.peek_back() << " (Expected: 20)" << std::endl;

    return 0;
}