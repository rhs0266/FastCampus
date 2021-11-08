import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M, H;
    static int[][][] dist, a;
    static int[][] dir = { {1,0,0,},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1}, {0,0,-1} };
    
    static void input() {
        M = scan.nextInt();
        N = scan.nextInt();
        H = scan.nextInt();
        a = new int[H + 1][N + 1][M + 1];
        dist = new int[H + 1][N + 1][M + 1];
        for (int h = 1; h <= H; h++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    a[h][i][j] = scan.nextInt();
                }
            }
        }
    }

    static void bfs() {
        // 초기화 해주기
        /* TODO */

        // BFS 과정 시작
        /* TODO */
    }

    static void pro() {
        int ans = 0;
        // bfs 수행 이후에 정답 계산하기
        System.out.println(ans);
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