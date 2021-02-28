import java.io.*;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static String[] a;

    static void input() {
        N = scan.nextInt();
        a = new String[N+1];
        for (int i = 1; i <= N; i++) {
            a[i] = scan.nextLine().split("\\.")[1];
        }
    }

    static void pro() {
        Arrays.sort(a, 1, N + 1);

        for (int i = 1; i <= N;) {
            // a[i] 와 같은 모든 것을 하나씩 찾는다.
            int cnt = 1, j = i + 1;
            for (;j <= N; j++){
                if (a[j].compareTo(a[i]) == 0) cnt++;
                else break;
            }

            sb.append(a[i]).append(' ').append(cnt).append('\n');

            // a[j] 가 a[i] 랑 다른 상황! 즉, 다음 i 는 j 부터 시작하면 된다.
            i = j;
        }

        // 정답 출력하기
        System.out.println(sb.toString());
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