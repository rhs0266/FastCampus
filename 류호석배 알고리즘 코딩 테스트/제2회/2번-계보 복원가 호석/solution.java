// javac t.java & java t

import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        FastReader scan = new FastReader();
        Map<String, Integer> s2i = new HashMap<>();
        int n, m;
        n = scan.nextInt();
        String i2s[] = new String[n+1];
        int adjmat[][] = new int[n+1][n+1];
        ArrayList<String> names = new ArrayList<String>();
        for(int i = 1; i <= n; i++){
            names.add(scan.next());
        }
        Collections.sort(names);
        for(int i = 1; i <= n; i++){
            i2s[i] = names.get(i-1);
            s2i.put(i2s[i], i);
        }
        m = scan.nextInt();
        int deg[] = new int[n+1];
        int chnum[] = new int[n+1];
        int chstate[][] = new int[n+1][n+1];
        for(int i = 0; i < m; i++){
            String a, b;
            a = scan.next(); b = scan.next();
            int u = s2i.get(a);
            int v = s2i.get(b);
            deg[u]++;
            adjmat[u][v] = 1;
        }
        ArrayList<String> anc = new ArrayList<String>();
        for(int i = 1; i <= n; i++){
            if(deg[i] == 0) anc.add(i2s[i]);
        }


        for(int tt = 0; tt < n; tt++){
            int idx = 1;
            while(deg[idx] > 0) idx++;
            for(int nxt = 1; nxt <= n; nxt++){
                if(adjmat[nxt][idx] == 1){
                    deg[nxt]--;
                    if(deg[nxt] == 0){
                        chnum[idx]++;
                        chstate[idx][nxt] = 1;
                    }
                }
            }
            deg[idx] = 99999999;
        }


        out.println(anc.size());
        for(int i = 0; i < anc.size(); i++) out.print(anc.get(i) + " ");
        out.println();
        for(int i = 1; i <= n; i++){
            out.print(i2s[i] + " " + chnum[i] + " ");
            for(int j = 1; j <= n; j++){
                if(chstate[i][j] == 1)
                    out.print(i2s[j] + " ");
            }
            out.println();
        }
        out.close();
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