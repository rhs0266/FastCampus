import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[][][][] Dy;
    static final int MOD = 1000000000;

    static void input() {
        N = scan.nextInt();
        Dy = new int[N + 1][10][10][10];
    }

    static void pro() {
        // 초기값 구하기
        for (int num = 1; num <= 9; num++) {
            Dy[1][num][num][num] = 1;
        }

        // 점화식을 토대로 Dy 배열 채우기
        for (int len = 2; len <= N; len++) {
            for (int prev = 0; prev <= 9; prev++) {
                for (int low = 0; low <= 9; low++) {
                    for (int high = 0; high <= 9; high++) {
                        for (int cur: new int[]{prev - 1, prev + 1}) {
                            if (cur < 0 || cur > 9) continue;
                            Dy[len][cur][Math.min(low, cur)][Math.max(high, cur)] += Dy[len - 1][prev][low][high];
                            Dy[len][cur][Math.min(low, cur)][Math.max(high, cur)] %= MOD;
                        }
                    }
                }
            }
        }

        // Dy배열로 정답 계산하기
        int ans = 0;
        for (int num = 0; num <= 9; num++) {
            ans += Dy[N][num][0][9];
            ans %= MOD;
        }

        System.out.println(ans);
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