#include "testlib.h"
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

struct Node {
    double data;
    Node* left;
    Node* right;

    Node(double value) : data(value), left(nullptr), right(nullptr) {}
};

Node* createBinaryTree(const std::vector<double>& values) {
    if (values.empty())
        return nullptr;

    Node* root = new Node(values[0]);
    std::queue<Node*> nodesQueue;
    nodesQueue.push(root);

    size_t i = 1;
    while (i < values.size()) {
        Node* current = nodesQueue.front();
        nodesQueue.pop();

        if (values[i] >= 0) {
            current->left = new Node(values[i]);
            nodesQueue.push(current->left);
        }

        ++i;
        if (i < values.size() && values[i] >= 0) {
            current->right = new Node(values[i]);
            nodesQueue.push(current->right);
        }
        ++i;
    }

    return root;
}

void deleteBinaryTree(Node* root) {
    if (root == nullptr)
        return;

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

std::vector<double> getBFSOrder(Node* root) {
    std::vector<double> result;
    if (root == nullptr)
        return result;

    std::queue<Node*> nodesQueue;
    nodesQueue.push(root);

    while (!nodesQueue.empty()) {
        Node* current = nodesQueue.front();
        nodesQueue.pop();
        result.push_back(current->data);

        if (current->left != nullptr)
            nodesQueue.push(current->left);
        if (current->right != nullptr)
            nodesQueue.push(current->right);
    }

    return result;
}

int main(int argc, char* argv[]) {
    setName("сравнение BFS-обхода бинарного дерева");

    registerTestlibCmd(argc, argv);

    std::vector<double> expected_values;
    std::vector<double> actual_values;

    if (ouf.eof()) {
        quitf(_pe, "Вывод пустой или не может быть прочитан");
    }

    std::string expectedLine;
    try {
        expectedLine = ans.readString();
    } catch (const std::exception& e) {
        quitf(_fail, "Не удалось прочитать ожидаемый ответ: %s", e.what());
    }

    std::istringstream expectedIss(expectedLine);
    double value;
    while (expectedIss >> value) {
        expected_values.push_back(value);
    }

    std::string actualLine;
    try {
        actualLine = ouf.readString(); 
    } catch (const std::exception& e) {
        quitf(_pe, "Не удалось прочитать фактический ответ: %s", e.what());
    }

    std::istringstream actualIss(actualLine);
    while (actualIss >> value) {
        actual_values.push_back(value);
    }

    if (expected_values.size() != actual_values.size()) {
        quitf(_wa, "Ожидаемая длина BFS-обхода %d, фактическая длина %d", expected_values.size(), actual_values.size());
    }

    Node* expectedTree = createBinaryTree(expected_values);
    Node* actualTree = createBinaryTree(actual_values);

    std::vector<double> expected_bfs = getBFSOrder(expectedTree);
    std::vector<double> actual_bfs = getBFSOrder(actualTree);

    if (expected_bfs != actual_bfs) {
        quitf(_wa, "Неверный ответ");
    }

    deleteBinaryTree(expectedTree);
    deleteBinaryTree(actualTree);

    quitf(_ok, "BFS-обход верен");
}
