import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int K, N, M;
    static int[] indeg, order, maxCnt;
    static ArrayList<Integer>[] adj;

    static void input() {
        K = scan.nextInt();
        N = scan.nextInt();
        M = scan.nextInt();
        adj = new ArrayList[N + 1];
        indeg = new int[N + 1];
        order = new int[N + 1];
        maxCnt = new int[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            int x = scan.nextInt(), y = scan.nextInt();
            adj[x].add(y);
            indeg[y]++;
        }
    }

    static void pro() {
        Deque<Integer> queue = new LinkedList<>();
        // 제일 앞에 "정렬될 수 있는" 정점 찾기
        /* TODO */

        // Strahler 순서를 고려해서 위상정렬을 수행하자.
        int ans = 0;
        /* TODO */
        System.out.println(K + " " + ans);
    }

    public static void main(String[] args) {
        int T = scan.nextInt();
        while (T-- > 0) {
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