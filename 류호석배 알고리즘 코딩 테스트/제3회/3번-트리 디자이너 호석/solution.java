import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n;
    static ArrayList<Integer>[] adj;
    static int[] a;
    static int[][] dy;
    static final int MOD = 1000000007;

    static void input() {
        n = scan.nextInt();
        adj = new ArrayList[n + 1];
        a = new int[n + 1];
        dy = new int[n + 1][10];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

        for (int i = 1; i <= n; i++) a[i] = scan.nextInt();

        // 인접 리스트 구성하기
        for (int i = 1; i < n; i++) {
            int x = scan.nextInt(), y = scan.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }
    }

    // dfs(x, par) := 정점 x 의 부모가 par 였고, x의 children들을 찾아주는 함수
    static void dfs(int x, int par) {
        dy[x][a[x]] = 1;
        for (int y : adj[x]) {
            if (y == par) continue;
            dfs(y, x);

            for (int num = 0; num <= 9; num++) {
                dy[x][num] += dy[y][num];
                dy[x][num] %= MOD;
            }
            for (int num = a[x]; num <= 9; num++) {
                dy[x][a[x]] += dy[y][num];
                dy[x][a[x]] %= MOD;
            }
        }
    }

    static void pro() {
        // 1 번 정점이 ROOT 이므로, 여기서 시작해서 Tree의 구조를 파악하자.
        dfs(1, -1);

        int ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans += dy[1][i];
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