import java.io.*;
import java.util.*;

public class Main {
    static int n, m, k;
    static String[] board;
    static int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
    static int dy[] = {1, -1, -1, 0, 1, -1, 0, 1};
    static Map<String, Integer> M = new HashMap<String, Integer>();
    static FastReader scan = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        k = scan.nextInt();
        board = new String[n];
        for (int i = 0; i < n; i++) {
            board[i] = scan.nextLine();
        }
    }

    static void pro() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // (i, j)에서 시작했을 때 만들 수 있는 문자열의 모든 경우 파악하기
                dfs(i, j, Character.toString(board[i].charAt(j)), 1);
            }
        }

        while (k-- > 0) {
            String chk = scan.nextLine();
            // 입력을 받으면 바로 Map 에서 정답을 가져온다
            if (M.containsKey(chk)) out.println(M.get(chk));
            else out.println(0);
        }
        out.close();
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    // 지금 (i, j)에 서 있고, 지금까지 만든 문자열이 path 이며 총 len 개의 문자를 만들었을 때
    // 앞으로 가능한 모든 경우를 탐색해주는 함수
    static void dfs(int i, int j, String path, int len) {
        // path 라는 문자열을 만들었음을 기록해주기
        if (M.containsKey(path)) M.put(path, M.get(path) + 1);
        else M.put(path, 1);

        // 최대 5개를 밟았으니 더 이상은 탐색을 하지 않는다.
        if (len == 5) return;

        // 8 방향으로 이동하기
        for (int dir = 0; dir < 8; dir++) {
            int ni = (i + dx[dir]) % n;
            int nj = (j + dy[dir]) % m;
            if (ni < 0) ni += n;
            if (nj < 0) nj += m;

            // 새로 밟을 문자: board[ni].charAt(nj)
            dfs(ni, nj, path + board[ni].charAt(nj), len + 1);
        }
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