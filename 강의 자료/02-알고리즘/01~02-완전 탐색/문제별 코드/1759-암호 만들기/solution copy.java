import java.io.*;
import java.util.*;

public class Main {
    static StringBuilder sb = new StringBuilder();

    static void input() {
        FastReader scan = new FastReader();
        M = scan.nextInt();
        N = scan.nextInt();
        chars = new char[N + 1];
        selected = new int[M + 1];
        String[] tokens = scan.nextLine().split(" ");
        for (int i = 1; i <= N; i++) {
            chars[i] = tokens[i - 1].charAt(0);
        }
    }

    static int N, M;
    static char[] chars;
    static int[] selected;

    static boolean isVowel(char x) {
        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
    }

    static void rec_func(int k) {
        if (k == M + 1) { // 1 ~ M 번째를 전부 다 골랐다
            int vowel = 0, consonant = 0;
            // 선택한 문자들이 조건을 만족하는 지 확인하자
            /* TODO */
        } else {
            // 알파벳 순으로 증가하는 순서로 골라보기
            /* TODO */
        }
    }

    public static void main(String[] args) {
        input();

        // 1 번째 원소부터 M 번째 원소를 조건에 맞는 모든 방법을 찾아줘
        // chars 정렬해주기
        /* TODO */
        rec_func(1);
        System.out.println(sb.toString());

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