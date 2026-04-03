package com.hexeong.programmers;

import java.util.*;

public class PGM_92343 {
    public int maxSheep = 0;

    public int solution(int[] info, int[][] edges) {
        // 인접 리스트 생성 (tree 역할)
        List<List<Integer>> edges_adj = new ArrayList<>();
        for (int i = 0; i < info.length; i++) {
            edges_adj.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            edges_adj.get(edge[0]).add(edge[1]);
        }

        // 다음에 방문 가능한 노드 목록 초기화
        List<Integer> nextNodes = new ArrayList<>();
        // 0번 노드는 이미 방문했으므로 0번의 자식들을 후보군에 넣음
        for (int child : edges_adj.get(0)) {
            nextNodes.add(child);
        }

        // 0번 노드는 항상 양이므로 (1, 0)에서 시작
        solve(1, 0, nextNodes, info, edges_adj);

        return maxSheep;
    }

    public void solve(int sheep, int wolf, List<Integer> nextNodes, int[] info, List<List<Integer>> adj) {
        maxSheep = Math.max(maxSheep, sheep);

        for (int i = 0; i < nextNodes.size(); i++) {
            int next = nextNodes.get(i);
            int nextSheep = sheep + (info[next] == 0 ? 1 : 0);
            int nextWolf = wolf + (info[next] == 1 ? 1 : 0);

            if (nextSheep > nextWolf) {
                // 새로운 후보지 목록 생성 (Deep Copy)
                List<Integer> list = new ArrayList<>(nextNodes);
                list.remove(i); // 현재 가기로 결정한 노드는 후보에서 제거

                // 현재 노드의 자식들을 새로운 후보군으로 추가
                for (int child : adj.get(next)) {
                    list.add(child);
                }

                solve(nextSheep, nextWolf, list, info, adj);
            }
        }
    }
}