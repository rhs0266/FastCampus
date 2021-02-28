import java.io.*;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static String[] A, ans;

    static void input() {
        N = scan.nextInt();
        A = new String[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = scan.nextLine();
        }
    }

    static boolean bin_search(String[] A, int L,int R, String X){
        while (L <= R){
            int mid = (L+R)/2;
            if (A[mid].equals(X))
                return true;

            if (A[mid].compareTo(X) < 0)
                L = mid + 1;
            else
                R = mid - 1;
        }
        return false;
    }

    static void pro() {
        int M = scan.nextInt(), ansCnt = 0;
        ans = new String[N + 1];
        Arrays.sort(A, 1, N + 1);
        for (int i = 1; i <= M; i++) {
            String X = scan.nextLine();
            if (bin_search(A, 1, N, X)) ans[++ansCnt] = X;
        }
        Arrays.sort(ans, 1, ansCnt + 1);
        sb.append(ansCnt).append('\n');
        for (int i = 1; i <= ansCnt; i++) sb.append(ans[i]).append('\n');
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