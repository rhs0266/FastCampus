import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static int N, ans_min, ans_max;
    static PrintWriter out = new PrintWriter(System.out);

    static void input(){
        FastReader scan = new FastReader();
        N = scan.nextInt();
    }

    static void pro(){
        ans_min = 0x7fffffff;
        ans_max = 0;
        // 시작하는 순간에는 N 이라는 숫자와, 여기에 속한 홀수 개수 만큼이 포함된다.
        dfs(N, get_odd_cnt(N));
        System.out.println(ans_min + " " + ans_max);
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    // x 라는 수 안에 홀수의 개수를 return하는 함수
    static int get_odd_cnt(int x){
        int res = 0;
        while (x > 0){
            int digit = x % 10;
            if (digit % 2 == 1) res++;
            x /= 10;
        }
        return res;
    }
    // x 라는 수에 도달했으며, 이때까지 등장한 홀수 자릿수가 total_odd_cnt 만큼 있을 때, 남은 경우를 모두 잘라보는 함수
    static void dfs(int x, int total_odd_cnt) {

        // 만약 한 자리 수면 더 이상 작업을 반복할 수 없으므로 정답을 갱신하고 종료한다.
        if (x <= 9) {
            ans_min = min(ans_min, total_odd_cnt);
            ans_max = max(ans_max, total_odd_cnt);
            return;
        }

        // 만약 두 자리 수면 2개로 나눠서 재귀 호출한다.
        if (x <= 99) {
            int next_x = (x / 10) + (x % 10);
            dfs(next_x, get_odd_cnt(next_x) + total_odd_cnt);
            return;
        }

        // 만약 세 자리 이상의 수면 가능한 3가지 자르는 방법을 모두 진행한다.
        String s = Integer.toString(x);
        for (int i = 0; i <= s.length() - 3; i++) {
            for (int j = i + 1; j <= s.length() - 2; j++) {
                String x1 = s.substring(0, i + 1);  // s[0...i]
                String x2 = s.substring(i + 1, j + 1);  // s[i+1...j]
                String x3 = s.substring(j + 1, s.length());  // s[j+1...end]

                // 나눠진 세 수를 더해서 재귀 호출
                int next_x = Integer.parseInt(x1) + Integer.parseInt(x2) + Integer.parseInt(x3);
                dfs(next_x, get_odd_cnt(next_x) + total_odd_cnt);
            }
        }
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