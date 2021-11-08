import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M, sx, sy;
    static int[][] dist;
    static int[][] dir = {{-1,-2},{-2,-1},{-1,2},{-2,1},{1,-2},{2,-1},{1,2},{2,1}};
    
    static void input() {
        N = scan.nextInt();
        M = scan.nextInt();
        sx = scan.nextInt();
        sy = scan.nextInt();
        dist = new int[N + 1][N + 1];
    }

    static void bfs() {
        // 초기화 해주기
        /* TODO */
        
        // BFS 과정 시작
        /* TODO */
    }

    static void pro() {
        bfs();
        while (M-- > 0) {
            int ex = scan.nextInt();
            int ey = scan.nextInt();
            System.out.print(dist[ex][ey]+ " ");
        }
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