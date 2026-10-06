#include <iostream>

// Чертеж структуры
struct Node {
    int data;
    Node* next;

    // Конструктор объекта
    Node(int val) {
        data = val; // 4 байта
        next = nullptr; // Адрес следующего узла. По умолчанию 0. Дальше будет 8 (hex адрес).
        // Плюс выравнивание (4 байта). Итого один Node: 16 байт памяти, в пространстве адресов.
    }
};

void print_list(Node* head) {
    Node* current = head; // Ну тут всё просто. берем head который хранит адрес узла, прячем в current. Относим к чертежу Node.
    while (current != nullptr) { //Пока не достигнем конца последнего узла.
        std::cout << current->data << " -> "; // достаем данные по адресу current
        current = current->next; // берем следующий узел
    }
    std::cout << "nullptr" << std::endl;
}

void free_list(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* next_node = current->next; // Сразу берем следующий узел
        delete current; // удаляем текущий вместе со всеми данными
        current = next_node; // Обновляем текущий узел
    }
    std::cout << "linked list is cleared" << std::endl;
}

int main() {

    // на этом уровне абстракции создаем узлы вручную для примера
    
    /*
        Node* x = new Node(10); — мы создали объект типа Node — выделили в памяти компьютера
        пространство адресов которое будет хранить информацию об объекте (data и next (следующий адрес)). 
        Вернули адрес выделенного пространства (объекта) и сохранили в переменную x.
        Теперь переменная x — указатель, потому что она хранит адрес другого объекта.
        А тип Node* означает, что переменная хранит адрес объекта данного типа (в нашем случае кастомного типа).
    */

    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    // Связываем узлы
    head->next = second;
    second->next = third;

    std::cout << "Linked list:" << std::endl;

    print_list(head);

    free_list(head);

    return 0;
}