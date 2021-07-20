import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);

    static class Info {
        int x, y, move, dist;
        
        public Info(){
            
        }

        public Info(int x, int y, int move, int dist) {
            this.x = x;
            this.y = y;
            this.move = move;
            this.dist = dist;
        }
    }

    static int n, m, sx, sy, ex, ey;
    static int[][] a;
    static int[][][] dist;

    static void input() {
        FastReader scan = new FastReader();
        n = scan.nextInt();
        m = scan.nextInt();
        sx = scan.nextInt();
        sy = scan.nextInt();
        ex = scan.nextInt();
        ey = scan.nextInt();
        a = new int[n + 2][m + 2];
        dist = new int[n + 2][m + 2][3];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                a[i][j] = scan.nextInt();
            }
        }
    }
    
    static int dir[][][] = {
        {{1, 0}, {-1, 0}},  // 3K + 1 번째 이동
        {{0, 1}, {0,  -1}},  // 3K + 2 번째 이동
        {{1, 0}, {0,  1}, {-1, 0}, {0, -1}}  // 3K 번째 이동
    };

    static void pro() {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                for (int k = 0; k < 3; k++)
                    dist[i][j][k] = Integer.MAX_VALUE;
    
        dist[sx][sy][0] = 0;
        PriorityQueue<Info> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.dist));
        pq.add(new Info(sx, sy, 0, 0));
        dist[sx][sy][0] = 0;
    
        while (!pq.isEmpty()) {
            Info info = pq.poll();
            int x = info.x, y = info.y, move = info.move, cost = info.dist;
            if (dist[x][y][move] != cost) continue;
            int choice = move == 2 ? 4 : 2;
            for (int k = 0; k < choice; k++) {
                int nx = x + dir[move][k][0];
                int ny = y + dir[move][k][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (a[nx][ny] == -1) continue;
    
                int nmove = (move + 1) % 3;
                int ncost = cost + a[nx][ny];
                if (dist[nx][ny][nmove] <= ncost) continue;
                dist[nx][ny][nmove] = ncost;
                pq.add(new Info(nx, ny, nmove, ncost));
            }
        }
    
        int ans = Integer.MAX_VALUE;
        for (int move = 0; move < 3; move++) {
            ans = Math.min(ans, dist[ex][ey][move]);
        }
        if (ans == Integer.MAX_VALUE) ans = -1;
        out.println(ans);
        out.close();
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