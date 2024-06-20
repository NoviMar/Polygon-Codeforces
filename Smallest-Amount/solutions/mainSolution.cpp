#include <iostream>
#include <stack>
#include <vector>

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
    }
}

std::vector<float> findMinBranch(Node* root) {
    std::vector<float> minBranch;
    std::stack<std::pair<Node*, std::vector<float>>> stack;
    stack.push({root, {root->data}});

    while (!stack.empty()) {
        auto [current, currentBranch] = stack.top();
        stack.pop();

        if (current->right != nullptr) {
            std::vector<float> rightBranch = currentBranch;
            rightBranch.push_back(current->right->data);
            stack.push({current->right, rightBranch});
        }

        if (current->left != nullptr) {
            std::vector<float> leftBranch = currentBranch;
            leftBranch.push_back(current->left->data);
            stack.push({current->left, leftBranch});
        }

        if (currentBranch.size() > minBranch.size()) {
            minBranch = currentBranch;
        }
    }

    return minBranch;
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

        std::vector<float> minBranch = findMinBranch(root);

        for (float element : minBranch) {
            std::cout << element << " ";
        }

        delete root;
    } else {
        std::cout << "Дерево не содержит вершин";
    }

    return 0;
}
