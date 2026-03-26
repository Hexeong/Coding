package com.hexeong.programmers;

import java.util.*;

public class PGM_42892 {
    static int[][] answer;
    static int idx;

    public static void main(String[] args) {
        System.out.println(Arrays.deepToString(solution(new int[9][2])));
    }

    public static int[][] solution(int[][] nodeinfo) {
        int n = nodeinfo.length;
        List<Node> nodes = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            nodes.add(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
        }

        nodes.sort((a, b) -> {
            if (a.y == b.y) return a.x - b.x;
            return b.y - a.y;
        });

        Node root = nodes.get(0);
        for (int i = 1; i < nodes.size(); i++) {
            insertNode(root, nodes.get(i));
        }

        answer = new int[2][n];
        idx = 0;
        preOrder(root);
        idx = 0;
        postOrder(root);

        return answer;
    }

    private static void insertNode(Node parent, Node child) {
        if (child.x < parent.x) {
            if (parent.left == null) parent.left = child;
            else insertNode(parent.left, child);
        } else {
            if (parent.right == null) parent.right = child;
            else insertNode(parent.right, child);
        }
    }

    // 전위 순회
    private static void preOrder(Node node) {
        if (node == null) return;
        answer[0][idx++] = node.id;
        preOrder(node.left);
        preOrder(node.right);
    }

    // 후위 순회
    private static void postOrder(Node node) {
        if (node == null) return;
        postOrder(node.left);
        postOrder(node.right);
        answer[1][idx++] = node.id;
    }

    static class Node {
        int id, x, y;
        Node left, right;

        public Node(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }
    }
}
