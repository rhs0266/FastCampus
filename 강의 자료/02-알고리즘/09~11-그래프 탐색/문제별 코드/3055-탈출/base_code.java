import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N, M;
    static String[] a;
    static int[][] dist_water, dist_hedgehog;
    static boolean[][] visit;
    static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static ArrayList<Integer> group;

    static void input() {
        N = scan.nextInt();
        M = scan.nextInt();
        a = new String[N];
        for (int i = 0; i < N; i++)
            a[i] = scan.nextLine();
        visit = new boolean[N][M];
        dist_water = new int[N][M];
        dist_hedgehog = new int[N][M];
    }

    // 모든 물들을 시작으로 동시에 BFS 시작!
    static void bfs_water() {
        Queue<Integer> Q = new LinkedList<>();
        // 모든 물의 위치를 Q에 전부 넣어주기!
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // dist_water 와 visit 배열 초기화
                /* TODO */
                if (a[i].charAt(j) == '*') {
                    /* TODO */
                }
            }
        }

        // BFS 과정 시작
        /* TODO */
    }

    // 고슴도치를 시작으로 동시에 BFS 시작!
    static void bfs_hedgehog() {
        Queue<Integer> Q = new LinkedList<>();
        // 고슴도치 위치를 Q에 넣어주기!
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // dist_hedgehog 와 visit 배열 초기화
                /* TODO */
                if (a[i].charAt(j) == 'S') {
                    /* TODO */
                }
            }
        }
        
        // BFS 과정 시작
        /* TODO */
    }

    static void pro() {
        // 각 칸마다 물에 닿는 시간 계산하기
        bfs_water();

        // 고슴도치가 물을 피해 탐색할 수 있는 공간 찾기
        bfs_hedgehog();

        // 탈출구 'D' 에 대한 결과를 통해 정답 출력하기
        for (int i=0;i<N;i++){
            for (int j=0;j<M;j++){
                if (a[i].charAt(j) == 'D'){
                    /* TODO */
                }
            }
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