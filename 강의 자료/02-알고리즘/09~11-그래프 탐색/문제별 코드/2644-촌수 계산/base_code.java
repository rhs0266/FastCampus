import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, st, ed, M;
    static ArrayList<Integer>[] adj;
    static int[] dist;

    static void input() {
        N = scan.nextInt();
        st = scan.nextInt();
        ed = scan.nextInt();
        M = scan.nextInt();
        adj = new ArrayList[N + 1];
        for (int i = 1;i <= N; i++)
            adj[i] = new ArrayList<>();
        for (int i = 1; i <= M; i++) {
            int x = scan.nextInt(), y = scan.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }
    }

    // start 에서 시작해서 갈 수 있는 정점들을 모두 탐색하기
    static void bfs(int start) {
        /* TODO */
    }

    static void pro() {
        dist = new int[N + 1];
        bfs(st);
        System.out.println(dist[ed]);
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