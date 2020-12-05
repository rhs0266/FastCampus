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
        // A[L ... R] 이 정렬되어 있다고 가정했을 때
        // 이 안에서 X 를 이분탐색하고, 존재하면 true, 아니면 false 를 return 하는 함수
        return false;
    }

    static void pro() {
        // 보도 못한 사람들을 입력 받으면서 듣도 못한 사람들 안에서 찾아주기
        // 정답을 기록해서 사전순으로 출력해주기
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