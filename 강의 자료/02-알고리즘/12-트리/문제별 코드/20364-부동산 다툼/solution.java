import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n, Q;
    static boolean[] estate;

    static void input() throws IOException {
        n = scan.nextInt();
        Q = scan.nextInt();
        estate = new boolean[n + 1];
    }

    static void pro() {
        // 사고 싶은 땅에서 시작해서 루트 땅까지 올라오면서 정답을 찾으면 편하다.
        // 왜냐하면 부모 노드는 찾기 쉽기 때문이다.
        while (Q-- > 0){
            int x = scan.nextInt(), res = 0;
            int y = x;
            while (x > 0) {
                if (estate[x]) res = x;
                x >>= 1;
            }
            estate[y] = true;
            sb.append(res).append('\n');
        }
        System.out.println(sb);
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
