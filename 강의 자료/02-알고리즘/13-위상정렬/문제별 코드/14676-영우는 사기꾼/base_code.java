import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int K, N, M;
    static int[] indeg, cnt, satisfaction;
    static ArrayList<Integer>[] adj;

    static void input() {
        N = scan.nextInt();
        M = scan.nextInt();
        K = scan.nextInt();
        adj = new ArrayList[N + 1];
        indeg = new int[N + 1];
        cnt = new int[N + 1];
        satisfaction = new int[N + 1];
        for (int i = 1; i <= N; i++)
            adj[i] = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            int x = scan.nextInt(), y = scan.nextInt();
            adj[x].add(y);
            indeg[y]++;
        }
    }

    static void pro() {
        boolean abnormal = false;
        while (K-- > 0) {
            int t = scan.nextInt(), x = scan.nextInt();
            if (t == 1){
                // x 의 선행 건물들이 모두 지어졌는 지 확인하기
                /* TODO */
                
                // x 의 개수 증가
                cnt[x]++;

                // x 가 처음 지어진 것이라면 x가 영향을 주는 건물들에 "너희의 선행 건물 중 하나가 처음 지어졌어" 라고 알려주기
                /* TODO */
            }
            else{
                // x 라는 건물이 한 개 이상 지어져 있는 지 확인하기
                /* TODO */
                
                // x 의 개수 감소
                cnt[x]--;

                // x 가 더 이상 남아있지 않다면, "너희의 선행 건물 중 하나가 사라졌어" 라고 알려주기
                /* TODO */
            }
        }
        if (abnormal) System.out.println("Lier!");
	    else System.out.println("King-God-Emperor");
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