import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0) {
            int m = sc.nextInt();
            int[] arr = new int[m];
            for(int i = 0; i < m; i++)
                arr[i] = sc.nextInt();
            // Please write your code here.

            PriorityQueue<Integer> left = new PriorityQueue<>((a, b) -> b - a);
            PriorityQueue<Integer> right = new PriorityQueue<>();

            int mid = -1;

            for (int i = 0; i < m; i++) {
                if (mid == -1)
                    mid = arr[i];
                else {
                    if (i % 2 == 0) { // 홀수
                        if (!right.isEmpty() && right.peek() < arr[i]) {
                            if (left.size() < right.size()) {
                                left.add(mid);
                                mid = right.poll();
                                right.add(arr[i]);
                            } else {
                                right.add(arr[i]);
                            }
                        } else if (!left.isEmpty() && arr[i] < left.peek()) {
                            if (left.size() < right.size()) {
                                left.add(arr[i]);
                            } else {
                                right.add(mid);
                                mid = left.poll();
                                left.add(arr[i]);
                            }
                        } else { // left.peek() <= arr[i] <= right.peek()
                            if (arr[i] < mid) {
                                if (left.size() < right.size()) 
                                    left.add(arr[i]);
                                else {
                                    right.add(mid);
                                    mid = arr[i];
                                }
                            } else if (mid < arr[i]) {
                                if (left.size() < right.size()) {
                                    left.add(mid);
                                    mid = arr[i];
                                }
                                else {
                                    right.add(arr[i]);
                                }
                            } else {
                                if (left.size() < right.size())
                                    left.add(arr[i]);
                                else
                                    right.add(arr[i]);
                            }
                        }
                    } else { // 짝수
                        if (mid >= arr[i]) {
                            left.add(arr[i]);
                        } else {
                            right.add(arr[i]);
                        }
                    }
                }

                if (i % 2 == 0) {
                    System.out.print(mid + " ");
                }
            }

            System.out.println();
        }
    }
}