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
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= N; i++) dist[i] = -1;

        // start는 방문 가능한 점이므로 que에 넣어준다.
        que.add(start);
        dist[start] = 0;  // start를 갈 수 있다고 표시하기 (중요!!!)

        while (!que.isEmpty()) {  // 더 확인할 점이 없다면 정지
            int x = que.poll();

            for (int y: adj[x]){
                if (dist[y] != -1) continue;  // x 에서 y 를 갈 수는 있지만, 이미 탐색한 점이면 무시
                // y를 갈 수 있으니까 que에 추가하고, visit 처리 하기!
                que.add(y);
                dist[y] = dist[x] + 1;
            }
        }
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