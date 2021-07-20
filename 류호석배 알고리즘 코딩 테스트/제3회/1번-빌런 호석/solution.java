import java.io.*;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, K, P, X;
    static int[][] num_flag = {
            {1, 1, 1, 0, 1, 1, 1},
            {0, 0, 1, 0, 0, 1, 0},
            {1, 0, 1, 1, 1, 0, 1},
            {1, 0, 1, 1, 0, 1, 1},
            {0, 1, 1, 1, 0, 1, 0},
            {1, 1, 0, 1, 0, 1, 1},
            {1, 1, 0, 1, 1, 1, 1},
            {1, 0, 1, 0, 0, 1, 0},
            {1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1, 1}
    };

    static void input() {
        N = scan.nextInt();
        K = scan.nextInt();
        P = scan.nextInt();
        X = scan.nextInt();
    }

    static int diff_one(int x, int y) {
        int res = 0;
        for (int i = 0; i < 7; i++) res += num_flag[x][i] != num_flag[y][i] ? 1 : 0;
        return res;
    }

    static int diff(int x, int y) {
        int res = 0;
        for (int rep = 1; rep <= K; rep++) {
            res += diff_one(x % 10, y % 10);
            x /= 10;
            y /= 10;
        }
        return res;
    }

    static void pro() {
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (i == X) continue;
            if (diff(i, X) <= P) ans++;
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