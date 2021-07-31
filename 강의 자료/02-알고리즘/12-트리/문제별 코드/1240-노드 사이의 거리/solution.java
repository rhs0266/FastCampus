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
        if (x == goal){
            ans = dist;
            return;
        }
        for (Edge e: con[x]){
            if (e.y == prev) continue;
            DFS(e.y, x, goal, dist + e.c);
        }
    }
    static void pro() {
        // 세 가지 풀이가 가능하다.
        // 1. 트리도 일종의 그래프이므로 최단거리 알고리즘인 Dijkstra 사용
        // 2. 트리에서 두 노드 사이의 경로는 유일한 점을 활용해서 BFS 사용
        // 3. 트리를 Rooted 트리로 변환해서 구현이 짧은 DFS를 통해 거리 계산하기.
        //    마찬가지로 두 노드 사이의 경로가 유일함을 확인한다.

        // 본 풀이는 3 번 접근을 다룬다.
        
        int x = scan.nextInt(), y = scan.nextInt();
        DFS(x, -1, y, 0);
        System.out.println(ans);
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