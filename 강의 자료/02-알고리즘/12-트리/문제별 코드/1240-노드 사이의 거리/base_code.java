import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static class Edge {
        int y, c;
        Edge(int y,int c){
            this.y = y;
            this.c = c;
        }
    }
    static int n, m;
    static ArrayList<Edge>[] con;

    static void input() throws IOException {
        n = scan.nextInt();
        m = scan.nextInt();
        con = new ArrayList[n + 1];
        for (int i=1;i<=n;i++) con[i]=new ArrayList<>();
        for (int i=1;i<n;i++){
            int x=scan.nextInt(), y=scan.nextInt(), c=scan.nextInt();
            con[x].add(new Edge(y, c));
            con[y].add(new Edge(x, c));
        }
    }

    static int ans;
    // 현재 x 에 있으며, 부모 노드는 prev 이며, 목표 지점은 goal,
    // 그리고 root부터 지금까지 이동 거리가 dist 이다.
    static void DFS(int x,int prev, int goal, int dist){
        /* TODO */
    }
    static void pro() {
        /* TODO */
    }

    public static void main(String[] args) throws IOException {
        input();
        while (m-- > 0) {
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