import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n, m;
    static int[] Dy;
    static ArrayList<Integer>[] children;

    static void input() throws IOException {
        n = scan.nextInt();
        m = scan.nextInt();
        Dy = new int[n + 1];
        children = new ArrayList[n+1];
        for (int i=1;i<=n;i++) children[i]=new ArrayList<>();
        for (int i=1;i<=n;i++){
            int par = scan.nextInt();
            if (i==1) continue;
            children[par].add(i);
        }
        for (int i=1;i<=m;i++){
            int x= scan.nextInt(), v= scan.nextInt();
            Dy[x] += v;
        }
    }

    // 내가 받은 칭찬을 부하 직원들에게 누적시켜주는 작업을 해주면 된다.
    static void DFS(int x){
        /* TODO */
    }

    static void pro() {
        /* TODO */
    }

    public static void main(String[] args) throws IOException {
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