#include <iostream>

struct Node {
    int value;
    Node* left{nullptr};
    Node* right{nullptr};

    explicit Node(int v) : value(v) {}
};

// Исследуем древо спокойно, не боясь случайных мутаций
bool isValidBSTHelper(const Node* root, long long min_bound, long long max_bound) {
    if (root == nullptr) return true;

    
    if (root->value <= min_bound || root->value >= max_bound) {
        return false;
    }


    return isValidBSTHelper(root->left, min_bound, root->value) && isValidBSTHelper(root->right, root->value, max_bound);
}

bool is_validBST(const Node* root) {
    return isValidBSTHelper(root, -9223372036854775807LL, 9223372036854775807LL);
}

// если оба значения меньше корня — идем налево, если больше — направо.
const Node* lowestCommonAncestor(const Node* root, const Node* p, const Node* q) {
    if (root == nullptr) return nullptr;

    const int root_val = root->value;
    const int p_val = p->value;
    const int q_val = q->value;

    if (p_val < root_val && q_val < root_val) {
        // углубляемся влево
        return lowestCommonAncestor(root->left, p, q);
    }

    if (p_val > root_val && q_val > root_val) {
        // углубляемся вправо
        return lowestCommonAncestor(root->right, p, q);
    }

    // Первый узел, где пути разделяются (или один из них равен корню) — это наименьший общий предок.
    return root;
}

// Рекурсивная зачистка памяти Кучи
void freeTreeRecursive(Node* root) {

    if (root == nullptr) return;

    if (root->left) freeTreeRecursive(root->left);
    if (root->right) freeTreeRecursive(root->right);

    delete root;
}

int main() {
    // сборка валидного BST
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);

    // Ищем предка (3) для узлов 1 и 4
    const Node* p = root->left->left;
    const Node* q = root->left->right;

    // const-correctness вызовов
    const bool is_bst_valid = is_validBST(root);
    const Node* lca_node = lowestCommonAncestor(root, p, q); // найменьший общий предок: узел со значением 3

    if (is_bst_valid) {
        std::cout << "Tree is a valid BST\n";
    } else {
        std::cout << "Tree is not a valid BST\n";
    }

    if (lca_node != nullptr) {
        std::cout << "lca value: " << lca_node->value << "\n";
    }

    // Не забываем очистить кучу
    freeTreeRecursive(root);

    root = nullptr;

    return 0;
}