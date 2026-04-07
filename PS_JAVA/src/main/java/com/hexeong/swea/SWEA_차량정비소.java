package com.hexeong.swea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class SWEA_차량정비소 {

    static class Customer {
        int num;                 // 고객 번호
        int arriveTime;          // 도착 시간
        int receptionRoomNum;    // 이용한 접수 창구 번호
        int repairRoomNum;       // 이용한 정비 창구 번호
        int receptionEndTime;    // 접수 종료 시간

        public Customer(int num, int arriveTime) {
            this.num = num;
            this.arriveTime = arriveTime;
        }
    }

    static class ReceptionUsing {
        Customer customer;
        int endTime;

        public ReceptionUsing(Customer customer, int endTime) {
            this.customer = customer;
            this.endTime = endTime;
        }
    }

    static class RepairUsing {
        Customer customer;
        int endTime;

        public RepairUsing(Customer customer, int endTime) {
            this.customer = customer;
            this.endTime = endTime;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            int[] receptionTime = new int[N + 1];
            int[] repairTime = new int[M + 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                receptionTime[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; i++) {
                repairTime[i] = Integer.parseInt(st.nextToken());
            }

            Customer[] customers = new Customer[K + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= K; i++) {
                customers[i] = new Customer(i, Integer.parseInt(st.nextToken()));
            }

            Queue<Customer> receptionWaitQ = new LinkedList<>();

            PriorityQueue<Customer> repairWaitQ = new PriorityQueue<>((c1, c2) -> {
                if (c1.receptionEndTime != c2.receptionEndTime) {
                    return c1.receptionEndTime - c2.receptionEndTime;
                }
                if (c1.receptionRoomNum != c2.receptionRoomNum) {
                    return c1.receptionRoomNum - c2.receptionRoomNum;
                }
                return c1.num - c2.num;
            });

            ReceptionUsing[] receptionRooms = new ReceptionUsing[N + 1];
            RepairUsing[] repairRooms = new RepairUsing[M + 1];

            int time = 0;
            int arrivedIdx = 1;
            int finishedCnt = 0;
            int result = 0;

            while (finishedCnt < K) {

                // 1) 현재 시각에 정비가 끝난 고객 처리
                for (int i = 1; i <= M; i++) {
                    if (repairRooms[i] != null && repairRooms[i].endTime == time) {
                        Customer c = repairRooms[i].customer;
                        if (c.receptionRoomNum == A && c.repairRoomNum == B) {
                            result += c.num;
                        }
                        repairRooms[i] = null;
                        finishedCnt++;
                    }
                }

                // 2) 현재 시각에 접수가 끝난 고객들을 정비 대기열로 이동
                for (int i = 1; i <= N; i++) {
                    if (receptionRooms[i] != null && receptionRooms[i].endTime == time) {
                        Customer c = receptionRooms[i].customer;
                        c.receptionEndTime = time;
                        repairWaitQ.offer(c);
                        receptionRooms[i] = null;
                    }
                }

                // 3) 현재 시각에 도착한 고객들을 접수 대기열에 추가
                while (arrivedIdx <= K && customers[arrivedIdx].arriveTime == time) {
                    receptionWaitQ.offer(customers[arrivedIdx]);
                    arrivedIdx++;
                }

                // 4) 빈 정비 창구에 대기 고객 배치
                for (int i = 1; i <= M; i++) {
                    if (repairRooms[i] == null && !repairWaitQ.isEmpty()) {
                        Customer c = repairWaitQ.poll();
                        c.repairRoomNum = i;
                        repairRooms[i] = new RepairUsing(c, time + repairTime[i]);
                    }
                }

                // 5) 빈 접수 창구에 대기 고객 배치
                for (int i = 1; i <= N; i++) {
                    if (receptionRooms[i] == null && !receptionWaitQ.isEmpty()) {
                        Customer c = receptionWaitQ.poll();
                        c.receptionRoomNum = i;
                        receptionRooms[i] = new ReceptionUsing(c, time + receptionTime[i]);
                    }
                }

                time++;
            }

            if (result == 0) result = -1;
            sb.append("#").append(tc).append(" ").append(result).append("\n");
        }

        System.out.print(sb);
    }
}
