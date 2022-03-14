import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int Q, MOD = 1000000009;
    static int[] Dy;

    static void input() {
        Q = scan.nextInt();
    }

    static void preprocess() {
        // Dy[i] := i 를 1, 2, 3의 합으로 표현하는 방법
        // Dy[0] 은 사실 문제 정의 상 말이 안되지만, 이후 점화식을 간단하게 적용하기 위해서
        // "아무것도 안 더한다"는 것을 하나의 경우로 생각해줘서 1을 적어준다.
        // 이를 통해서 Dy[1, 2, 3]에 대해서도 일관성있는 점화식을 작성할 수 있기 때문이다.
        // 이게 불편하다면 Dy[1, 2, 3] 에 대해 모두 값을 적어주고 시작해도 상관없다.
        /* TODO */
    }

    static void pro() {
        Dy = new int[1000005];
        preprocess();
        while (Q-- > 0) {
            int x = scan.nextInt();
            sb.append(Dy[x]).append('\n');
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