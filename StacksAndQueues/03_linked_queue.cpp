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
class LinkedQueue {
private:
    Node<T>* head; // Удаляются из головы (начало очереди)
    Node<T>* tail; // Добавляются с хвоста (конец очереди)
    std::size_t size; // счетчик элементов в очереди

public:
    LinkedQueue() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedQueue() {
        while (!is_empty()) {
            pop();
        }
    }

    void push(T val) {
        Node<T>* new_node = new Node<T>(val);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
    }

    T pop() {
        if (is_empty()) return T{};
        Node<T>* temp = head;

        T head_value = head->data;
        head = head->next;

        if (head == nullptr) {tail = nullptr;} // Обнуляем хвост
        else {head->prev = nullptr;};

        delete temp;

        size--;

        return head_value;
    }

    T peek() {
        if (is_empty()) return T{};

        return head->data;
    }

    bool is_empty() {
        return head == nullptr;
    }

    Node<T>* get_top_ptr() {
        if (is_empty()) return nullptr;
        return head;
    }

    std::size_t get_size() {
        return size;
    }
};

int main() {
    LinkedQueue<int> queue;

    queue.pop(); // Test pop on empty queue
    queue.push(88); // Test push on empty queue

    queue.pop(); // Test pop on queue with one element

    for (int i = 1; i <= 5; i++) {
        queue.push(i * 10);
    }

    std::cout << "Queue address: " << queue.get_top_ptr() << "\n";

    std::cout << "First in queue: " << queue.peek() << " (Expected: 10)" << std::endl;
    std::cout << "Served (pop): " << queue.pop() << " (Expected: 10)" << std::endl;
    std::cout << "Next in queue: " << queue.peek() << " (Expected: 20)" << std::endl;

    return 0;
}