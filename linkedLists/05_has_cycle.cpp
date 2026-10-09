#include <iostream>
#include "linked_list_base.h"

// Поиск циклов
bool has_cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; 
        fast = fast->next->next;

        // Если fast догнал slow, значит список зациклен
        if (slow == fast) {
            return true;
        }
    }

    return false; // fast наткнулся на nullptr, следовательно список конечен.
}

void break_cycle(Node*& head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Если догнали
            fast = head; // Ставим fast в начало списка.

            if (slow == fast) { // Если встретились в голове
                Node* current = head;
                while (current->next != head) current = current->next;
                current->next = nullptr;
                return;
            }

            // Идем с одинаковой скоростью пока узлы не совпадут
            while (fast->next != slow->next) {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = nullptr;
            return;

        }
    }
}



int main() {
    Node* head = nullptr;

    for (int i = 5; i >= 1; i--) {
        insert_at_head(head, (i * 10));
    }

    // Искусственно зацикливаем список

    Node* current = head;
    while (current->next != nullptr) current = current->next;

    Node* loop = head->next;
    current->next = loop;

    if (has_cycle(head)) {
        std::cout << "Dynamic loop has detected in RAM" << std::endl;
    } else {
        std::cout << "List dont have a loop" << std::endl;
    }

    // Перед очисткой связного списка с петлей, петлю важно обязательно разорвать.
    // Так как логику поиска хвоста использовать бессмысленно, 
    // то мы немного изменим логику has_cycle чтобы найти место в котором петлю можно разорвать
    break_cycle(head);

    if (has_cycle(head)) {
        std::cout << "Dynamic loop has detected in RAM" << std::endl;
    } else {
        std::cout << "List dont have a loop" << std::endl;
    }

    free_list(head);

    return 0;
}