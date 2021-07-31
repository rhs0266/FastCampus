import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    // 모든 leaf node 들의 깊이의 합이 짝수냐 홀수냐가 승리 요건
    // sum_leaf_depth: 모든 leaf node 들의 깊이의 합
    static int n, sum_leaf_depth;
    static ArrayList<Integer>[] con;

    static void input() throws IOException {
        n = scan.nextInt();
        con = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            con[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            int x = scan.nextInt(), y = scan.nextInt();
            con[x].add(y);
            con[y].add(x);
        }
    }

    // 트리를 순회하면서 sum_leaf_depth 계산
    static void dfs(int x, int prev, int depth) {
        if (x != 1 && con[x].size() == 1) sum_leaf_depth += depth;
        for (int y : con[x]) {
            if (y == prev) continue;
            dfs(y, x, depth + 1);
        }
    }

    static void pro() {
        dfs(1, -1, 0);
        if (sum_leaf_depth % 2 == 0) System.out.println("No");
        else System.out.println("Yes");
    }

    public static void main(String[] args) throws IOException {
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