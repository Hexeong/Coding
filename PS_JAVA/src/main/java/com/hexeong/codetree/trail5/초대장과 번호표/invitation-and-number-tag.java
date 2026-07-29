import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int g = sc.nextInt();
        
        // 1. 각 그룹을 HashSet으로 관리하여 사람을 빠르게 지울 수 있도록 함
        List<Set<Integer>> groups = new ArrayList<>();
        
        // 2. 어떤 사람이 어떤 그룹들에 속해 있는지 저장 (빠른 탐색을 위해)
        List<List<Integer>> personToGroups = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            personToGroups.add(new ArrayList<>());
        }
        
        for (int i = 0; i < g; i++) {
            int size = sc.nextInt();
            Set<Integer> group = new HashSet<>();
            for (int j = 0; j < size; j++) {
                int person = sc.nextInt();
                group.add(person);
                personToGroups.get(person).add(i); // 이 사람이 i번 그룹에 속해 있음을 기록
            }
            groups.add(group);
        }
        
        // 3. 연쇄 초대를 관리할 Queue와 방문 배열(초대 여부)
        Queue<Integer> q = new LinkedList<>();
        boolean[] invited = new boolean[n + 1];
        
        // 초기 조건: 1번 사람은 무조건 초대
        q.add(1);
        invited[1] = true;
        int cnt = 0;
        
        // 4. 큐가 빌 때까지(더 이상 연쇄 초대되는 사람이 없을 때까지) 반복
        while (!q.isEmpty()) {
            int p = q.poll(); // 새롭게 초대받은 사람
            cnt++;
            
            // 이 사람이 속해 있던 모든 그룹을 찾아갑니다.
            for (int groupIdx : personToGroups.get(p)) {
                Set<Integer> group = groups.get(groupIdx);
                
                // 그룹에서 이 사람을 지웁니다. (이미 초대받았으므로)
                group.remove(p);
                
                // 그룹에 남은 사람이 딱 1명이라면? -> 그 사람도 무조건 초대!
                if (group.size() == 1) {
                    int lastPerson = group.iterator().next(); // 남은 1명 꺼내기
                    
                    if (!invited[lastPerson]) { // 아직 초대받지 않은 사람이라면
                        invited[lastPerson] = true;
                        q.add(lastPerson); // 새롭게 큐에 추가 (연쇄 작용 시작)
                    }
                }
            }
        }
        
        System.out.println(cnt);
    }
}