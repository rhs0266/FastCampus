import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static ArrayList<Integer>[] adj;
    static int[] dist;

    static void input() {
        N = scan.nextInt();
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

    // start 라는 정점의 케빈 베이컨의 수를 계산해주는 함수
    static int bfs(int start) {
        int ret = 0;
        Queue<Integer> que = new LinkedList<>();
        for (int i = 1; i <= N; i++) dist[i] = -1;

        // start는 방문 가능한 점이므로 que에 넣어준다.
        que.add(start);
        dist[start] = 0;  // start를 갈 수 있다고 표시하기 (중요!!!)

        while (!que.isEmpty()) {  // 더 확인할 점이 없다면 정지
            int x = que.poll();
            ret += dist[x];

            for (int y: adj[x]){
                if (dist[y] != -1) continue;  // x 에서 y 를 갈 수는 있지만, 이미 탐색한 점이면 무시
                // y를 갈 수 있으니까 que에 추가하고, visit 처리 하기!
                que.add(y);
                dist[y] = dist[x] + 1;
            }
        }
        return ret;
    }

    static void pro() {
        dist = new int[N + 1];
        int minV = bfs(1), minIdx = 1;
        for (int i = 2; i <= N; i++) {
            int v = bfs(i);
            if (minV > v){
                minV = v;
                minIdx = i;
            }
        }
        System.out.println(minIdx);
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