#include <iostream>

// Чистая структура узла. 24 байта в Куче. Никаких скрытых оберток.
struct Node {
    int value;
    Node* left{nullptr};
    Node* right{nullptr};

    explicit Node(int val) : value(val) {}
};

// --- ШАГ 1.4: ВАЛИДАЦИЯ BST ---
// Строгая const-correctness: дерево исследуется без права на мутацию.
bool isValidBSTHelper(const Node* root, long long min_bound, long long max_bound) {
    if (root == nullptr) return true;

    // Проверка физических границ диапазона для текущего регистра значения
    if (root->value <= min_bound || root->value >= max_bound) {
        return false;
    }

    // Рекурсивный спуск: левый узел зажимается сверху, правый — снизу
    return isValidBSTHelper(root->left, min_bound, root->value) &&
           isValidBSTHelper(root->right, root->value, max_bound);
}

bool isValidBST(const Node* root) {
    // Инициализируем границы абсолютными минимумами/максимумами 64-битного целого
    return isValidBSTHelper(root, -9223372036854775807LL, 9223372036854775807LL);
}

// --- ШАГ 1.4: ПОИСК LCA В BST ---
// Используем свойства BST: если оба значения меньше корня — идем налево, если больше — направо.
// Первый узел, где пути разделяются (или один из них равен корню) — это наименьший общий предок.
const Node* lowestCommonAncestor(const Node* root, const Node* p, const Node* q) {
    if (root == nullptr) return nullptr;

    // Локальные кэш-переменные для Watch-панели
    const int root_val = root->value;
    const int p_val = p->value;
    const int q_val = q->value;

    if (p_val < root_val && q_val < root_val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p_val > root_val && q_val > root_val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root; // Точка разделения найдена
}

// Итеративная безопасная зачистка памяти Кучи без риска Stack Overflow
void freeTreeIterative(Node* root) {
    if (root == nullptr) return;
    // В реальном коде тут использовался бы стек в куче, но для учебного полигона
    // пока оставим простую рекурсию, так как глубина нашего дерева контролируема.
    if (root->left) freeTreeIterative(root->left);
    if (root->right) freeTreeIterative(root->right);
    delete root;
}

int main() {
    // Сборка Валидного Бинарного Дерева Поиска (BST) в RAM:
    //        5
    //       / \
    //      3   8
    //     / \
    //    1   4
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    // Указатели-шпионы для задачи LCA (ищем предка для узлов 1 и 4, ожидаем 3)
    const Node* p = root->left->left;   // Узел со значением 1
    const Node* q = root->left->right;  // Узел со значением 4

    // Вызовы алгоритмов
    const bool is_bst_valid = isValidBST(root);
    const Node* lca_node = lowestCommonAncestor(root, p, q);

    // ТОЧКА ОСТАНОВА (Breakpoint) ДЛЯ ДЕБАГГЕРА:
    if (is_bst_valid) {
        std::cout << "Tree is a valid BST.\n";
    } else {
        std::cout << "Tree is NOT a valid BST.\n";
    }

    if (lca_node != nullptr) {
        std::cout << "LCA value: " << lca_node->value << "\n";
    }

    // Освобождение Кучи
    freeTreeIterative(root);
    root = nullptr;

    return 0;
}
