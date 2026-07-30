import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Please write your code here.

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] people = new int[n + 1][3];
        for (int i = 1; i <= n; i++) {
            people[i][0] = sc.nextInt(); // 도착시간
            people[i][1] = sc.nextInt(); // 머무르는 시간
            people[i][2] = i;
        }

        Arrays.sort(people, (a, b) -> {
            return a[0] - b[0];
        });

        PriorityQueue<Person> pq = new PriorityQueue<>((a, b) -> {
            return a.num - b.num;
        });

        int t = 0;
        int pn = 1;
        int gardenLeavingTime = 0;

        int max_res = 0;
        while (pn <= n || !pq.isEmpty()) {
            // 해당 시간에 도착하는 사람이 있다면 
            if (pn <= n && people[pn][0] <= t) {
                // System.out.println("in : " + people[pn][2]);
                pq.add(new Person(people[pn][2], people[pn][0], people[pn][1]));
                pn++;
            }
            // 대기자가 있으면 대기 명단에서 빼서 채우기
            if (t >= gardenLeavingTime && !pq.isEmpty()) {
                Person target = pq.poll();
                // System.out.println("out : " + target.num);
                max_res = Math.max(max_res, t - target.arrival);
                gardenLeavingTime = t + target.staying;
            }
            
            boolean flag = true;
            if (gardenLeavingTime != 0 && t < gardenLeavingTime) {
                t = gardenLeavingTime;
                flag = false;
            }
            if (pn <= n && people[pn][0] < t) {
                t = people[pn][0];
                flag = false;
            }
            if (flag)
                t++;
        }

        System.out.println(max_res);
    }

    static class Person {
        int arrival;
        int staying;
        int num;

        public Person(int num, int arrival, int staying) {
            this.num = num;
            this.arrival = arrival;
            this.staying = staying;
        }
    }

}