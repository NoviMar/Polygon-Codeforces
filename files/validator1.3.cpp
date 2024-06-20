#include "testlib.h"
#include <vector>
#include <limits.h>

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

bool isBinaryTree(Node* node, int minValue, int maxValue) {
    if (node == nullptr) {
        return true;
    }

    if (node->value < minValue || node->value > maxValue) {
        return false;
    }

    return isBinaryTree(node->left, minValue, node->value - 1) &&
           isBinaryTree(node->right, node->value + 1, maxValue);
}

bool isBinaryTreeFromValues(const std::vector<int>& values);

void validateBinaryTree() {
    int n = inf.readInt(0, 100, "n");
    inf.readEoln();

    if (n == 0) {
        printf("Дерево не содержит вершин\n");
        inf.readEof(); 
        return;
    }

    std::vector<int> values;
    int count = 0;

    while (!inf.seekEoln()) {
        int value = inf.readInt(-100, 100);
        values.push_back(value);
        count++;
        if (count<n)
            inf.readSpace(); 
    }
    
    if (count != n) { 
        quitf(_wa, "Количество вершин не соответствует заданному числу");
    }
    
    bool hasNegative = std::any_of(values.begin(), values.end(), [](int v){ return v < 0; });
    if (!hasNegative) {
        quitf(_wa, "Отсутствуют вершины с отрицательным значением");
    }
    inf.readEof();
}

bool isBinaryTreeFromValues(const std::vector<int>& values) {
    int n = values.size();
    std::vector<Node*> nodes(n + 1, nullptr);
    bool hasNegative = false;

    for (int i = 1; i <= n; i++) {
        if (values[i-1] < 0) {
            hasNegative = true;
        }
        nodes[i] = new Node(values[i-1]);
    }

    if (!hasNegative) {
        return false;
    }

    return isBinaryTree(nodes[1], INT_MIN, INT_MAX);
}

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    validateBinaryTree();
    return 0;
}
