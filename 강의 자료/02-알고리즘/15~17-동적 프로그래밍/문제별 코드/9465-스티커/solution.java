import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[][] Dy;
    static int[][] A;
    
    static void input(){
        N = scan.nextInt();
        A = new int[N + 1][2];
        Dy = new int[N + 1][3];
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= N; i++) {
                A[i][j] = scan.nextInt();
            }
        }
    }

    static void pro() {
        // 초기값 구하기
        Dy[1][1] = A[1][0];
        Dy[1][2] = A[1][1];
    
        // 점화식을 토대로 Dy 배열 채우기
        for (int i = 2; i <= N; i++) {
            for (int prev = 0; prev <= 2; prev++) {
                Dy[i][0] = Math.max(Dy[i][0], Dy[i - 1][prev]);
                for (int j = 0; j <= 1; j++) {
                    if ((prev & (1 << j)) != 0) continue;
                    Dy[i][1 << j] = Math.max(Dy[i][1 << j], Dy[i - 1][prev] + A[i][j]);
                }
            }
        }
        System.out.println(Math.max(Math.max(Dy[N][0], Dy[N][1]), Dy[N][2]));
    }

    public static void main(String[] args) {
        int TT = scan.nextInt();
        while (TT-- > 0) {
            input();
            pro();
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