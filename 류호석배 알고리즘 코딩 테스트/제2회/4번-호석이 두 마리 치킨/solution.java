// javac t.java & java t

import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        FastReader scan = new FastReader();
        int n, m;
        n = scan.nextInt();
        m = scan.nextInt();
        int adjmat[][] = new int[n+1][n+1];
        for(int i = 0; i < m; i++){
            int a = scan.nextInt();
            int b = scan.nextInt();
            adjmat[a][b] = adjmat[b][a] = 1;
        }
        int ans1 = -1, ans2 = -1, mn = 0x7f7f7f7f;


        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                int dist[] = new int[n+1];
                for(int k = 1; k <= n; k++) dist[k] = -1;
                dist[i] = dist[j] = 0;
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                q.add(j);
                int tot = 0;
                while(!q.isEmpty()){
                    int cur = q.poll();
                    for(int k = 1; k <= n; k++){
                        if(adjmat[k][cur] == 0) continue;
                        if(dist[k] != -1) continue;
                        dist[k] = dist[cur] + 1;
                        q.add(k);
                        tot += dist[k];
                    }
                }
                if(tot < mn){
                    ans1 = i;
                    ans2 = j;
                    mn = tot;
                }
            }
        }
        System.out.println(ans1 + " " + ans2 + " " + mn*2);
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
    static class pair{
        public long x, y;
        pair(long x, long y){
            this.x = x;
            this.y = y;
        }
        pair(){
            this.x = 0;
            this.y = 0;
        }
    }
}