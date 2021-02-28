import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

// 물통의 현재 상태와 물을 붓는 행위를 관리하는 구조체
class State{
    int[] X;
    State(int[] _X){
        X = new int[3];
        for (int i=0;i<3;i++) X[i] = _X[i];
    }
    
    State move(int from,int to,int[] Limit){
        // from 물통에서 to 물통으로 물을 옮긴다.
        int[] nX = new int[]{X[0], X[1], X[2]};
        if (X[from] + X[to] <= Limit[to]){  // 만약 from 을 전부 부을 수 있다면
            nX[to] = nX[from] + nX[to];
            nX[from] = 0;
        }else{  // from 의 일부만 옮길 수 있는 경우
            nX[from] -= Limit[to] - nX[to];
            nX[to] = Limit[to];
        }
        return new State(nX);
    }
};

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int[] Limit;
    static boolean[] possible;
    static boolean[][][] visit;

    static void input() {
        Limit = new int[3];
        for (int i=0;i<3;i++) Limit[i] = scan.nextInt();
        visit = new boolean[205][205][205];
        possible = new boolean[205];
    }

    // 물통 탐색 시작~
    static void bfs(int x1, int x2, int x3) {
        Queue<State> Q = new LinkedList<>();
        visit[x1][x2][x3] = true;
        Q.add(new State(new int[]{x1, x2, x3}));

        // BFS 과정 시작
        while (!Q.isEmpty()) {
            State st = Q.poll();
            if (st.X[0] == 0) possible[st.X[2]] = true;
            for (int from = 0; from < 3; from++) {
                for (int to = 0; to < 3; to++) {
                    if (from == to) continue;
                    // i 번 물통에서 j 번 물통으로 물을 옮긴다.
                    State nxt = st.move(from, to, Limit);

                    // 만약 바뀐 상태를 탐색한 적이 없다면
                    if (!visit[nxt.X[0]][nxt.X[1]][nxt.X[2]]) {
                        visit[nxt.X[0]][nxt.X[1]][nxt.X[2]] = true;
                        Q.add(nxt);
                    }
                }
            }
        }
    }

    static void pro() {
        bfs(0, 0, Limit[2]);
        for (int i=0;i<=200;i++){
            if (possible[i]) sb.append(i).append(' ');
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