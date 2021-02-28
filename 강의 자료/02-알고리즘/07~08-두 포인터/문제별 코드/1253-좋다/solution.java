import java.io.*;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static int[] A;

    static void input() {
        N = scan.nextInt();
        A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = scan.nextInt();
        }
    }

    // target_idx 번째 원소가 서로 다른 두 수의 합으로 표현이 되는가?
    static boolean func(int target_idx) {
        int L = 1, R = N;
        int target = A[target_idx];
        while (L < R) {
            if (L == target_idx) L++;
            else if (R == target_idx) R--;
            else {
                if (A[L] + A[R] > target) R--;
                else if (A[L] + A[R] == target) return true;
                else L++;
            }
        }
        return false;
    }

    static void pro() {
        // 최소, 최대를 빠르게 알기 위한 정렬
        Arrays.sort(A, 1, N + 1);

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            // i 번째 원소가 서로 다른 두 수의 합으로 표현이 되는가?
            if (func(i)) ans++;
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