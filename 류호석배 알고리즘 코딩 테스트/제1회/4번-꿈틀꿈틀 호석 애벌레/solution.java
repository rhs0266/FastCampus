import java.io.*;
import java.util.*;


public class Main {
    static int n, K, D;
    static long[] a, dy;
    // a[x] : x 번 먹이의 만족도
    // dy[x] : x 번 먹이까지 먹어서 얻을 수 있는 최대 탈피 에너지
    static FastReader scan = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void input() {
        n = scan.nextInt();
        K = scan.nextInt();
        a = new long[n + 1];
        dy = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = scan.nextLong();
        }
    }

    static void pro() {
        int right = 1;
        long sum = 0, dyLeftMax = 0;
        // sum := 최근에 섭취하게 되는 만족도의 총합. (탈피 에너지가 아님)

        for (int left = 1; left <= n; left++) {
            // left 부터 먹기 시작할 것인 상태

            // dyLeftMax := 이전까지 얻을 수 있는 최대 탈피 에너지
            dyLeftMax = Math.max(dyLeftMax, dy[left - 1]);

            // right := 더 먹을 수 있는 음식의 번호
            while (right <= n && sum < K) {
                sum += a[right++];
            }
            // 이 시점에는 [left, ..., right - 1] 까지 먹었으며, right 는 먹지 않은 상태이다.
            // sum := a[left] + ... + a[right - 1]

            if (sum >= K) {
                // [left, ..., right - 1]의 음식을 먹었을 때 얻는 탈피 에너지 := sum - K
                dy[right - 1] = Math.max(dy[right - 1], dyLeftMax + (sum - K));
            }
            else break;

            // left 음식은 이제 안 먹게 되었으니 sum 에서 제거한다.
            sum -= a[left];
        }
        long ans = 0;
        for (int i = 1; i <= n; i++) ans = Math.max(ans, dy[i]);
        out.print(ans);
        out.close();
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}