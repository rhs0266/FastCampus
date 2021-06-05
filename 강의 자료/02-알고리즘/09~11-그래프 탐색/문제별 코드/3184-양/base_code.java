import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M, totalSheep, totalWolf, sheep, wolf;
    static String[] a;
    static boolean[][] visit;
    static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    static void input() {
        N = scan.nextInt();
        M = scan.nextInt();
        a = new String[N];
        for (int i = 0; i < N; i++)
            a[i] = scan.nextLine();
        visit = new boolean[N][M];
    }

    // x, y 를 갈 수 있다는 걸 알고 방문한 상태
    static void dfs(int x, int y) {
        // 연결된 영역 안에서 양과 늑대의 수를 계산하자.
        /* TODO */
    }

    static void pro() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visit[i][j] && a[i].charAt(j) != '#') {
                    // 갈 수 있는 칸인데, 아직 방문하지 않은, 즉 새롭게 만난 구역인 경우!
                    /* TODO */
                }
            }
        }

        sb.append(totalSheep).append(' ').append(totalWolf);
        System.out.println(sb.toString());
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