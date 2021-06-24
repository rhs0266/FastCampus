import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static int n, m, R, ans;
    static int[][] a, backup;
    static PrintWriter out = new PrintWriter(System.out);
    static FastReader scan = new FastReader();

    // board 의 상태를 입력받는 함수
    static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        R = scan.nextInt();
        a = new int[n + 1][m + 1];
        backup = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                a[i][j] = scan.nextInt();
                backup[i][j] = a[i][j];
            }
    }

    // 게임 순서에 맞게 진행시키는 함수
    static void pro() {
        for (int i = 1; i <= R; i++) {
            int X, Y;
            String dir;

            // 공격수 차례
            X = scan.nextInt();
            Y = scan.nextInt();
            dir = scan.next();
            attack(X, Y, dir.charAt(0));

            // 수비수 차례
            X = scan.nextInt();
            Y = scan.nextInt();
            a[X][Y] = backup[X][Y];
        }

        // 정답 출력
        System.out.println(ans);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 0) System.out.print("F ");
                else System.out.print("S ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    // x 행 y 열에 있는 도미노를 dir 방향으로 밀어버리는 함수
    static void attack(int x, int y, char dir) {
        if (a[x][y] == 0) return;

        // dx, dy 는 도미노가 넘어지는 방향을 좌표 변화량으로 표현한 것
        int dx = 0, dy = 0;
        if (dir == 'E') dy = 1;
        else if (dir == 'W') dy = -1;
        else if (dir == 'S') dx = 1;
        else if (dir == 'N') dx = -1;

        // cnt := 앞으로 더 넘어져야 하는 거리를 나타내는 변수
        int cnt = a[x][y];
        while (x >= 1 && x <= n && y >= 1 && y <= m && cnt >= 1) {
            if (a[x][y] != 0) ans++;

            // 이번에 넘어진 a[x][y] 에 의해서, 넘어져야 하는 거리가 더 길어지는 경우를 확인!
            cnt = max(cnt - 1, a[x][y] - 1);

            // 넘어뜨리기
            a[x][y] = 0;

            // 다음 방향 확인하기
            x += dx;
            y += dy;
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
