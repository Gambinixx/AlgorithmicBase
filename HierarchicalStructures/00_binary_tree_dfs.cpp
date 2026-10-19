#include <iostream>
#include <utility>
#include <memory>

class BinaryTree {
private:
    struct Node {
        int val;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    // Корневой узел, типа как head
    std::unique_ptr<Node> root;

    // Симметричный обход (inorder): левое поддерево, текущий узел, правое поддерево
    void inorder_impl(const Node* node) const {
        if (!node) return; // базовый случай, дошли до пустого узла. Завершаем эту ветвь рекурссии

        inorder_impl(node->left.get());
        std::cout << node->val << " ";
        inorder_impl(node->right.get());
    }

    // Ищем узел по значению во всём дереве и возвращаем указатель на него. 
    // Если узел не найден, возвращаем nullptr.

    Node* find_node(Node* node, int val) {
        if (!node) return nullptr;

        if (node->val == val) return node;

        // Сначала ищем в левом поддереве
        if (Node* found = find_node(node->left.get(), val)) {
            return found;
        }

        // Если в левом не нашли, возвращаем результат из правого поддерева
        return find_node(node->right.get(), val);
    }

public:
    BinaryTree() : root(nullptr) {} // Пустое древо по-умолчанию

    // СОздаем корень. Если дерево уже существовало то старое освобождается
    void set_root(int val) {
        root = std::make_unique<Node>(val);
    }

    // Находим родителя по значению и создаем ему левого ребенка
    void add_left(int parent_val, int child_val) {
        Node* parent = find_node(root.get(), parent_val);

        if (parent) {
            // Создаем новый узел и передаем владение им указателю parent->left
            parent->left = std::make_unique<Node>(child_val);
        }
    }

    void add_right(int parent_val, int child_val) {
        Node* parent = find_node(root.get(), parent_val);

        if (parent) {
            parent->right = std::make_unique<Node>(child_val);
        }
    }

    // Запускаем симметричный обходи из корня и выводим значение узлов
    void print() const {
        inorder_impl(root.get());
        std::cout << "\n";
    }
};

int main() { 
    // Объект дерева создаётся на стеке; узлы дерева выделяются динамически. 
    BinaryTree tree; 
    
    // Строим дерево: каждый вызов указывает значение родителя и нового ребёнка. 
    tree.set_root(1); 
    tree.add_left(1, 2); 
    tree.add_right(1, 3); 
    tree.add_left(2, 4); 
    tree.add_right(2, 5); 
    tree.add_left(4, 6); 

    std::cout << "Inorder traversal: "; 
    tree.print(); 

    return 0; // При уничтожении tree узлы автоматически освобождаются через unique_ptr. 
}