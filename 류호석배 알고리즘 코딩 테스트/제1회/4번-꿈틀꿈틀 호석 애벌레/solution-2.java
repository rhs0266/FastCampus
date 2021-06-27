import java.io.*;
import java.util.*;


public class Main {
    static class Interval{
        int left;
        long satisfy;
    }
    static int N, K;
    static long[] A, Dy;
    static ArrayList<Interval>[] intervals;
    // a[x] : x 번 먹이의 만족도
    // dy[x] : x 번 먹이까지 먹어서 얻을 수 있는 최대 탈피 에너지
    static FastReader scan = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void input() {
        N = scan.nextInt();
        K = scan.nextInt();
        A = new long[N + 1];
        Dy = new long[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = scan.nextLong();
        }
        intervals = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++){
            intervals[i] = new ArrayList<>();
        }
    }

    static void pro() {
        long sum = 0;
        for (int L = 1, R = 0; L <= N; L++){

            while (R + 1 <= N && sum < K) sum += A[++R];

            if (sum >= K) {
                Interval i = new Interval();
                i.left = L;
                i.satisfy = sum - K;
                intervals[R].add(i);
            }

            sum -= A[L];
        }

        for (int R = 1; R <= N; R++){
            Dy[R] = Dy[R-1];
            for (Interval i: intervals[R]){
                Dy[R] = Math.max(Dy[R], Dy[i.left - 1] + i.satisfy);
            }
        }

        out.print(Dy[N]);
        out.close();
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
