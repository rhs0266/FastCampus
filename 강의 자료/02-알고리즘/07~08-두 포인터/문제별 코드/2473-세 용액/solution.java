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

    static void pro() {
        // 최소, 최대 원소를 빠르게 찾기 위해서 정렬을 미리 해주자.
        Arrays.sort(A, 1, N + 1);

        long best_sum = Long.MAX_VALUE;
        int v1 = 0, v2 = 0, v3 = 0;
        for (int i = 1; i <= N - 2; i++){
            int target = -A[i];
            int L = i + 1, R = N;
            while (L < R){  // L == R 인 상황이면 용액이 한 개 뿐인 것이므로, L < R 일 때까지만 반복한다.
                if (best_sum > Math.abs(-(long)target + A[L] + A[R])) {
                    best_sum = Math.abs(-(long)target + A[L] + A[R]);
                    v1 = -target;
                    v2 = A[L];
                    v3 = A[R];
                }
                if (A[L] + A[R] > target) R--;
                else L++;
            }
        }
        sb.append(v1).append(' ').append(v2).append(' ').append(v3);
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
