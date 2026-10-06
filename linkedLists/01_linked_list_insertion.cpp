#include <iostream>

struct Node {
    int data;
    Node* next;
    // Компактная запись конструктора
    Node(int val) : data(val), next(nullptr) {}
};

// 1. Автомат: вставка в начало списка за O(1)
// Передаем объект Node*& по ссылке, чтобы функция могла изменить сам указатель head в main
void insert_at_head(Node*& head, int val) {
    Node* new_node = new Node(val); // Создаем новый узел
    new_node->next = head; // адрес следующего узла, это адрес текущей головы
    head = new_node; // объявляем новой головой списка
}

// 2. Автомат: вставка в конец списка за O(N)
void insert_at_tail(Node*& head, int val) {
    Node* new_node = new Node(val);

    // Если список пустой, новый узел сам становится головой
    if (new_node == nullptr) {
        head = new_node;
        return;
    }

    // Ищем хвост: бежим кареткой пока не упремся в узел у которого нет следующего
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    // пришиваем новый узел к бывшему хвосту
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
    while (current != nullptr) {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

int main() {
    Node* head = nullptr; // Изначально список абсолютно пустой

    // Автоматически набиваем список элементами в начало
    insert_at_head(head, 30);
    insert_at_head(head, 20);
    insert_at_head(head, 10);

    // Автоматически докидываем элементы в хвост
    insert_at_tail(head, 40);
    insert_at_tail(head, 50);

    std::cout << "Automated Linked List: ";
    print_list(head);

    free_list(head);
    return 0;
}