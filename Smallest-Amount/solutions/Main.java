import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    static void dfsAndPrint(Node root) {
        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.empty()) {
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

    static List<Integer> findMinBranch(Node root) {
        List<Integer> minBranch = new ArrayList<>();
        Stack<NodeBranchPair> stack = new Stack<>();
        stack.push(new NodeBranchPair(root, new ArrayList<Integer>() {{
            add(root.data);
        }}));

        while (!stack.empty()) {
            NodeBranchPair pair = stack.pop();
            Node current = pair.node;
            List<Integer> currentBranch = pair.branch;

            if (current.right != null) {
                List<Integer> rightBranch = new ArrayList<>(currentBranch);
                rightBranch.add(current.right.data);
                stack.push(new NodeBranchPair(current.right, rightBranch));
            }

            if (current.left != null) {
                List<Integer> leftBranch = new ArrayList<>(currentBranch);
                leftBranch.add(current.left.data);
                stack.push(new NodeBranchPair(current.left, leftBranch));
            }

            if (currentBranch.size() > minBranch.size()) {
                minBranch = currentBranch;
            }
        }

        return minBranch;
    }

    static class NodeBranchPair {
        Node node;
        List<Integer> branch;

        NodeBranchPair(Node node, List<Integer> branch) {
            this.node = node;
            this.branch = branch;
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

            List<Integer> minBranch = findMinBranch(root);

            for (int element : minBranch) {
                System.out.print(element + " ");
            }
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
}
