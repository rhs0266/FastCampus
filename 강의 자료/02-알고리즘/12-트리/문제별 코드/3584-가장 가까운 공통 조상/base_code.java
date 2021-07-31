import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n;
    static int[] par, check;

    static void input() throws IOException {
        n = scan.nextInt();
        par = new int[n + 1];
        check = new int[n + 1];
        for (int i=1;i<n;i++){
            int u = scan.nextInt(), v = scan.nextInt();
            par[v] = u;
        }
    }

    static void pro() {
        int x = scan.nextInt(), y = scan.nextInt();

        // x 에서 루트까지 체크를 해놓는다.
        /* TODO */

        // y 에서 루트로 이동하면서 처음으로 만나는 체크된 정점을 찾는다.
        /* TODO */

        System.out.println(y);
    }

    public static void main(String[] args) throws IOException {
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