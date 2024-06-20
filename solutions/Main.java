import java.util.Scanner;
import java.util.Stack;

public class Main {
    static void dfsAndPrint(Node root) {
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node current = stack.pop();
            System.out.print(current.data + " ");

            if (current.right != null) {
                stack.push(current.right);
            }
            if (current.left != null) {
                stack.push(current.left);
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        if (N != 0) {
            int first = scanner.nextInt();

            Node root = new Node(first);
            for (int i = 1; i < N; ++i) {
                int element = scanner.nextInt();
                root.insert(element);
            }

            root.replaceNegativeValues();
            dfsAndPrint(root);
        } else {
            System.out.println("Дерево не содержит вершин");
        }
    }
}
class Node {
    int data;
    Node left;
    Node right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }

    void insert(int value) {
        if (value <= data) {
            if (left == null) {
                left = new Node(value);
            } else {
                left.insert(value);
            }
        } else {
            if (right == null) {
                right = new Node(value);
            } else {
                right.insert(value);
            }
        }
    }

    void replaceNegativeValues() {
        if (data < 0) {
            data = -data;
        }
        if (left != null) {
            left.replaceNegativeValues();
        }
        if (right != null) {
            right.replaceNegativeValues();
        }
    }
}

