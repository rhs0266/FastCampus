import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static int[] indeg;
    static ArrayList<Integer>[] adj;

    static void input() {
        N = scan.nextInt();
        M = scan.nextInt();
        adj = new ArrayList[N + 1];
        indeg = new int[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int cnt  = scan.nextInt(), x = scan.nextInt(), y;
            // A1, A2, ... Acnt 순서로 나가야 한다면,
            // A1 -> A2
            // A2 -> A3
            // ...
            // A(cnt-1) -> Acnt
            // 의 간선을 만들어주면 된다.
            for (int j=2;j<=cnt;j++){
                y = scan.nextInt();
                adj[x].add(y);
                indeg[y]++;
                x = y;
            }
        }
    }

    static void pro() {
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 1; i <= N; i++)
            if (indeg[i] == 0)
                queue.add(i);


        // 우선순위에 대한 조건을 간선으로 표현했으므로 위상정렬을 수행하면 된다.
        ArrayList<Integer> ans = new ArrayList<>();
        while (!queue.isEmpty()) {
            int x = queue.poll();
            ans.add(x);
            for (int y : adj[x]) {
                indeg[y]--;
                if (indeg[y] == 0) queue.add(y);
            }
        }
        if (ans.size() == N)
            for (int x: ans) sb.append(x).append('\n');
        else sb.append(0);
        System.out.println(sb);
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