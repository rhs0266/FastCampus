import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n, X;
    static int[] a;

    static void input() {
        n = scan.nextInt();
        X = scan.nextInt();
        a = new int[n + 1];
        for (int i = 1; i <= n; i++) a[i] = scan.nextInt();
    }

    // 공정 라인을 num개 사용하면 X 시간 안에 전부 만들 수 있는가?
    static boolean determination(int num) {
        PriorityQueue<Integer> PQ;
        PQ = new PriorityQueue<>();
        for (int i = 1; i <= num; i++) PQ.add(0);

        for (int i = 1; i <= n; i++) {
            int pick = PQ.poll();
            if (pick + a[i] > X) return false;
            PQ.add(pick + a[i]);
        }
        return true;
    }

    static void pro() {
        int L = 1, R = n, ans = n;
        // Parametric search를 통해 최적의 K* 찾기
        while (L <= R) {
            int mid = (L + R) / 2;
            if (determination(mid)) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
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