import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // 1. Scanner 대신 BufferedReader와 StringTokenizer를 사용합니다.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[][] originalPoints = new int[n][2];
        
        TreeSet<Integer> xSet = new TreeSet<>();
        TreeSet<Integer> ySet = new TreeSet<>();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            originalPoints[i][0] = x;
            originalPoints[i][1] = y;
            xSet.add(x);
            ySet.add(y);
        }

        int[] uniqueX = new int[xSet.size()];
        int idx = 0;
        for (int x : xSet) uniqueX[idx++] = x;

        int[] uniqueY = new int[ySet.size()];
        idx = 0;
        for (int y : ySet) uniqueY[idx++] = y;

        int nx = uniqueX.length;
        int ny = uniqueY.length;

        int[][] areaSum = new int[nx + 1][ny + 1];

        for (int i = 0; i < n; i++) {
            int x = originalPoints[i][0];
            int y = originalPoints[i][1];
            
            int cx = Arrays.binarySearch(uniqueX, x) + 1;
            int cy = Arrays.binarySearch(uniqueY, y) + 1;
            
            areaSum[cx][cy]++;
        }

        for (int i = 1; i <= nx; i++) {
            for (int j = 1; j <= ny; j++) {
                areaSum[i][j] = areaSum[i][j] + areaSum[i - 1][j] + areaSum[i][j - 1] - areaSum[i - 1][j - 1];
            }
        }

        // 2. 출력을 매번 하지 않고 StringBuilder에 모아둡니다.
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            int cx1 = getMinIdx(uniqueX, x1);
            int cx2 = getMaxIdx(uniqueX, x2);
            int cy1 = getMinIdx(uniqueY, y1);
            int cy2 = getMaxIdx(uniqueY, y2);

            if (cx1 > cx2 || cy1 > cy2) {
                sb.append(0).append("\n");
            } else {
                int ans = areaSum[cx2][cy2] - areaSum[cx1 - 1][cy2] - areaSum[cx2][cy1 - 1] + areaSum[cx1 - 1][cy1 - 1];
                sb.append(ans).append("\n");
            }
        }
        
        // 3. 마지막에 한 번만 출력합니다.
        System.out.print(sb);
    }

    static int getMinIdx(int[] arr, int target) {
        int l = 0, r = arr.length - 1;
        int minIdx = arr.length;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) {
                minIdx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return minIdx + 1; 
    }

    static int getMaxIdx(int[] arr, int target) {
        int l = 0, r = arr.length - 1;
        int maxIdx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= target) {
                maxIdx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return maxIdx + 1;
    }
}