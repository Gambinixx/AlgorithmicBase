#include <iostream>
#include <memory>
#include <utility>

class BinaryTree {
private:
    struct Node {
        int val;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;

    // 1. Симметричный обход (inorder): лево -> корень -> право
    void inorder(const Node* node) const {
        if (!node) return;

        inorder(node->left.get());
        std::cout << node->val << " ";
        inorder(node->right.get());
    }

    // 2. Прямой обход (Preorder): Корень -> Лево -> Право
    void preorder(const Node* node) const {
        if (!node) return;

        std::cout << node->val << " "; // Сначала корень
        preorder(node->left.get()); // Левое поддерево
        preorder(node->right.get()); // Правое поддерево
    }

    // 3. Обратный обход (Postorder): Лево -> Право -> Корень
    void postorder(const Node* node) const {
        if (!node) return;

        postorder(node->left.get());
        postorder(node->right.get());
        std::cout << node->val << " ";
    }

    Node* find_node(Node* node, int val) {
        if (!node) return nullptr;

        if (node->val == val) return node;

        if (Node* found = find_node(node->left.get(), val)) {
            return found;
        }

        return find_node(node->right.get(), val);
    }

public:
    BinaryTree() : root(nullptr) {}

    void set_root(int val) {
        root = std::make_unique<Node>(val);
    }

    void add_left(int parent_val, int child_val) {
        Node* parent = find_node(root.get(), parent_val);

        if (parent) {
            parent->left = std::make_unique<Node>(child_val);
        }
    }

    void add_right(int parent_val, int child_val) {
        Node* parent = find_node(root.get(), parent_val);

        if (parent) {
            parent->right = std::make_unique<Node>(child_val);
        }
    }

    void print_in() const {
        inorder(root.get());
        std::cout << "\n";
    }

    void print_pre() const {
        preorder(root.get());
        std::cout << "\n";
    }

    void print_post() const {
        postorder(root.get());
        std::cout << "\n";
    }
};    

int main() {
    BinaryTree tree;

    // Строим тестовое дерево
    tree.set_root(1); 
    tree.add_left(1, 2); 
    tree.add_right(1, 3); 
    tree.add_left(2, 4); 
    tree.add_right(2, 5); 
    tree.add_left(4, 6); 

    std::cout << "Preorder  (Root->Left->Right): ";
    tree.print_pre(); // Ожидаем: 1 2 4 6 5 3

    std::cout << "Inorder   (Left->Root->Right): ";
    tree.print_in();  // Ожидаем: 6 4 2 5 1 3

    std::cout << "Postorder (Left->Right->Root): ";
    tree.print_post(); // Ожидаем: 6 4 5 2 3 1

    return 0;
}