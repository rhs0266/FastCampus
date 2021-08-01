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
        for (int i = 1; i <= N; i++)
            if (indeg[i] == 0){
                queue.add(i);
                order[i] = maxCnt[i] = 1;
            }


        // 정렬될 수 있는 정점이 있다면?
        // 1. 정렬 결과에 추가하기
        // 2. 정점과 연결된 간선 제거하기
        // 3. 새롭게 "정렬 될 수 있는" 정점 Queue에 추가하기
        int ans = 0;
        while (!queue.isEmpty()) {
            int x = queue.poll();
            // 만약 들어오는 순서 중 가장 큰 순서가 2개 이상이면 자신의 순서를 1 증가시킨다.
            if (maxCnt[x] >= 2) order[x]++;
            ans = Math.max(ans, order[x]);
            for (int y : adj[x]) {
                indeg[y]--;
                if (indeg[y] == 0) queue.add(y);
                // Stahler 순서 계산을 위해서 y번 정점에 들어오는 최대 순서를 갱신해준다.
                if (order[y] == order[x]) maxCnt[y]++;
                else if (order[y] < order[x]) {
                    order[y] = order[x];
                    maxCnt[y] = 1;
                }
            }
        }
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