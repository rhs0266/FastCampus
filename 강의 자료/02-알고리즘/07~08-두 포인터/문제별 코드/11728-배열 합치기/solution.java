import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int n, m;
    static int[] a, b;

    static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        a = new int[n + 1];
        b = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            a[i] = scan.nextInt();
        }
        for (int i = 1; i <= m; i++) {
            b[i] = scan.nextInt();
        }
    }

    static void pro() {
        int L = 1, R = 1;
        // a와 b를 앞에서부터 하나씩 추출해서 출력한다. 단, 둘 다 비어있지 않은 경우와 그것이 아닌 경우를 잘 나누자.
        while (L <= n && R <= m){
            if (a[L] <= b[R]) sb.append(a[L++]).append(' ');
            else sb.append(b[R++]).append(' ');
        }
        while (L <= n) sb.append(a[L++]).append(' ');
        while (R <= m) sb.append(b[R++]).append(' ');
        
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