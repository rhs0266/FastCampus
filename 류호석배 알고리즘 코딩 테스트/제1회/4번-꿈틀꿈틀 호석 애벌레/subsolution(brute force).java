import java.io.*;
import java.util.*;


public class Main {
    static int n, K, D;
    static long[] a, dy;
    static long ans;
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

    static void dfs(int idx, long energy) {
        ans = Math.max(ans, energy);

        long sum = 0;
        for (int r = idx; r <= n; r++) {
            sum += a[r];
            if (sum >= K) {
                dfs(r + 1, energy + (sum - K));
                break;
            }
        }
        dfs(idx + 1, energy);
    }

    static void pro() {
        dfs(1, 0);
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