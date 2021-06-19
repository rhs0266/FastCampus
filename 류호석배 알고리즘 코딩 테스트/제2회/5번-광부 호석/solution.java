// javac t.java & java t

import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter out = new PrintWriter(System.out);


    public static void main(String[] args) {
        FastReader scan = new FastReader();
        int n, c;
        n = scan.nextInt();
        c = scan.nextInt();
        ArrayList<pair>[] xx = new ArrayList[100001];
        ArrayList<pair>[] yy = new ArrayList[100001];
        for(int i = 0; i < 100001; i++){
            xx[i] = new ArrayList<pair>();
            yy[i] = new ArrayList<pair>();
        }
        for(int i = 0; i < n; i++){
            long x, y, v;
            x = scan.nextLong();
            y = scan.nextLong();
            v = scan.nextLong();
            xx[(int)x].add(new pair(y,v));
            yy[(int)y].add(new pair(x,v));
        }
        long mx = 0;
        long curval = 0;
        int curnum = 0;
        int xlim = 0;
        int ylim = 100000;

        while(xlim <= 100000){
            for(int i = 0; i < xx[xlim].size(); i++){
                if(xx[xlim].get(i).x > ylim) continue;
                curval += xx[xlim].get(i).y;
                curnum++;
            }
            while(curnum > c){
                for(int i = 0; i < yy[ylim].size(); i++){
                    if(yy[ylim].get(i).x > xlim) continue;
                    curval -= yy[ylim].get(i).y;
                    curnum--;
                }
                ylim--;
            }
            xlim++;
            if(mx < curval) mx = curval;
        }
        System.out.println(mx);
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