#include <iostream>
#include <stack>
#include <vector>
#include <ctime> 

class Node {
public:
    float data;
    Node* left;
    Node* right;

    Node(float value) : data(value), left(nullptr), right(nullptr) {}

    void insert(float value) {
        if (value <= data) {
            if (left == nullptr) {
                left = new Node(value);
            } else {
                left->insert(value);
            }
        } else {
            if (right == nullptr) {
                right = new Node(value);
            } else {
                right->insert(value);
            }
        }
    }
};

void dfsAndPrint(Node* root) {
    std::stack<Node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        std::cout << current->data << " ";
        if (current->right != nullptr) {
            stack.push(current->right);
        }
        if (current->left != nullptr) {
            stack.push(current->left);
        }

        clock_t start_time = clock();
        while ((clock() - start_time) / CLOCKS_PER_SEC < 1) {}
    }
}

int main() {
    int N;
    std::cin >> N;

    if (N != 0) {
        float first;
        std::cin >> first;

        Node* root = new Node(first);
        for (int i = 1; i < N; ++i) {
            float element;
            std::cin >> element;
            root->insert(element);
        }

        dfsAndPrint(root);

        delete root;
    } else {
        std::cout << "Дерево не содержит вершин";
    }

    return 0;
}
