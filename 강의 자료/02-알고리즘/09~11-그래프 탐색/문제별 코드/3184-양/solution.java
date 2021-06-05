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
        if (a[x].charAt(y) == 'o') sheep++;  // 양이 한 마리 발견됨
        if (a[x].charAt(y) == 'v') wolf++;  // 늑대가 한 마리 발견됨
        visit[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;  // 지도를 벗어나는 곳으로 가는가?
            if (a[nx].charAt(ny) == '#') continue;  // 갈 수 있는 칸인지 확인해야 한다.
            if (visit[nx][ny]) continue;  // 이미 방문한 적이 있는 곳인가?
            dfs(nx, ny);
        }
    }

    static void pro() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visit[i][j] && a[i].charAt(j) != '#') {
                    // 갈 수 있는 칸인데, 이미 방문처리 된, 즉 새롭게 만난 단지인 경우!
                    sheep = 0;
                    wolf = 0;
                    dfs(i, j);
                    if (sheep > wolf) totalSheep += sheep;  // 양이 더 많았다.
                    else totalWolf += wolf;  // 늑대가 더 많았다.
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