import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int Q;
    static long[][] Dy;

    static void input(){
        Q = scan.nextInt();
    }

    // Dy[][] 를 미리 계산해 놓기
    static void preprocess() {
        // Dy[i][k] := fibonacci(i) 를 호출했을 때, k 가 출력되는 횟수
        Dy[0][0] = 1;
        Dy[1][1] = 1;
        for (int i = 2; i <= 40; i++) {
            Dy[i][0] = Dy[i - 1][0] + Dy[i - 2][0];
            Dy[i][1] = Dy[i - 1][1] + Dy[i - 2][1];
        }
    }

    static void pro() {
        Dy = new long[40 + 1][2];
        preprocess();

        for (int i = 1; i <= Q; i++){
            int q = scan.nextInt();
            sb.append(Dy[q][0]).append(' ').append(Dy[q][1]).append('\n');
        }
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