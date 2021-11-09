import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, S, M;
    static boolean[][] Dy;
    static int[] A;

    static void input() {
        N = scan.nextInt();
        S = scan.nextInt();
        M = scan.nextInt();
        A = new int[N + 1];
        Dy = new boolean[N + 1][M + 1];
        for (int i = 1; i <= N; i++)
            A[i] = scan.nextInt();
    }

    static void pro() {
        // 초기값 구하기
        Dy[0][S] = true;

        // 점화식을 토대로 Dy 배열 채우기
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            boolean flag = false;
            ans = 0;
            for (int prev = 0; prev <= M; prev++) {
                if (!Dy[i - 1][prev]) continue;
                for (int cur : new int[]{prev - A[i], prev + A[i]}) {
                    if (cur < 0 || cur > M) continue;
                    ans = Math.max(ans, cur);
                    Dy[i][cur] = true;
                    flag = true;
                }
            }
            if (!flag) {
                System.out.println(-1);
                return;
            }
        }

        // Dy배열로 정답 계산하기
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