import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static final int MOD = 9901;
    static int[][] Dy;
    
    static void input(){
        N = scan.nextInt();
        Dy = new int[N + 1][3];
    }

    static void pro() {
        // 초기값 구하기
        Dy[1][0] = 1;
        Dy[1][1] = 1;
        Dy[1][2] = 1;
    
        // 점화식을 토대로 Dy 배열 채우기
        for (int i = 2; i <= N; i++) {
            for (int prev = 0; prev <= 2; prev++) {
                Dy[i][0] += Dy[i - 1][prev];
                Dy[i][0] %= MOD;
                for (int j = 0; j <= 1; j++) {
                    if ((prev & (1 << j)) != 0) continue;
                    Dy[i][1 << j] += Dy[i - 1][prev];
                    Dy[i][1 << j] %= MOD;
                }
            }
        }
        System.out.println((Dy[N][0] + Dy[N][1] + Dy[N][2]) % MOD);
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