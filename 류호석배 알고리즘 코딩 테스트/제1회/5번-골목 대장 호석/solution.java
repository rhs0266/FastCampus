import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);

    static class Info implements Comparable<Info> {
        int idx;
        long length;

        public Info(int idx, long length) {
            this.idx = idx;
            this.length = length;
        }

        @Override
        public int compareTo(Info o) {
            if (length > o.length) return 1;
            if (length == o.length) return 0;
            return -1;
        }
    }

    static int n, m, a, b;
    static long c;
    static List<Info> adj[];
    static long INF = 10000000000000001L;
    static long[] d;

    static void input() {
        FastReader scan = new FastReader();
        n = scan.nextInt();
        m = scan.nextInt();
        a = scan.nextInt();
        b = scan.nextInt();
        c = scan.nextLong();
        adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            int u, v;
            long t;
            u = scan.nextInt();
            v = scan.nextInt();
            t = scan.nextLong();
            adj[u].add(new Info(v, t));
            adj[v].add(new Info(u, t));
        }
    }

    static void pro() {
        d = new long[n + 1];
        long left = 1, right = 1000000001, ans = right;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (dijkstra(mid)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        if (ans == 1000000001) ans = -1;
        out.println(ans);
        out.close();
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    static boolean dijkstra(long x) {
        for (int i = 1; i <= n; i++) d[i] = INF;
        d[a] = 0;
        PriorityQueue<Info> queue = new PriorityQueue<>();
        queue.add(new Info(a, 0));
        while (!queue.isEmpty()) {
            Info cur = queue.poll();
            if (d[cur.idx] != cur.length) continue;
            for (Info edge : adj[cur.idx]) {
                if (edge.length > x) continue;
                if (d[edge.idx] > d[cur.idx] + edge.length) {
                    d[edge.idx] = d[cur.idx] + edge.length;
                    queue.add(new Info(edge.idx, d[edge.idx]));
                }
            }
        }
        return d[b] <= c;
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