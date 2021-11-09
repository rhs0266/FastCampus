import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[][] dy_min, dy_max;
    static int[] A;
    
    static void input(){
        N = scan.nextInt();
        A = new int[4];
        dy_min = new int[2][4];
        dy_max = new int[2][4];
    }

    static void pro() {
        // 초기값 구하기
        for (int j = 1; j <= 3; j++) {
            dy_min[1][j] = scan.nextInt();
            dy_max[1][j] = dy_min[1][j];
        }

        // 점화식을 토대로 Dy 배열 채우기
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= 3; j++) A[j] = scan.nextInt();
            for (int cur = 1; cur <= 3; cur++) {
                dy_max[i % 2][cur] = 0;
                dy_min[i % 2][cur] = 10000000;
                for (int prev = 1; prev <= 3; prev++) {
                    if (Math.abs(cur - prev) > 1) continue;
                    dy_max[i % 2][cur] = Math.max(dy_max[i % 2][cur], dy_max[(i + 1) % 2][prev] + A[cur]);
                    dy_min[i % 2][cur] = Math.min(dy_min[i % 2][cur], dy_min[(i + 1) % 2][prev] + A[cur]);
                }
            }
        }
        System.out.print(Math.max(Math.max(dy_max[N % 2][1], dy_max[N % 2][2]), dy_max[N % 2][3]) + " ");
	    System.out.print(Math.min(Math.min(dy_min[N % 2][1], dy_min[N % 2][2]), dy_min[N % 2][3]) + " ");
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