// javac t.java & java t

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static long lim[] = new long[38];
    static PrintWriter out = new PrintWriter(System.out);
    static long MX = 0x7fffffffffffffffL;
    static long c2i(char x){
        if('0' <= x && x <= '9') return (long)(x - '0');
        return (long)(10L + x - 'a');
    }
    static long calc(String s, int m){
        long ret = 0;
        for(int i = 0; i < s.length(); i++){
            if(ret > lim[m]) return -1L;
            ret *= m;
            if(c2i(s.charAt(i)) >= m || lim[m] - c2i(s.charAt(i)) < ret) return -1L;
            ret = ret + c2i(s.charAt(i));
        }
        return ret;
    }
    public static void main(String[] args) {
        FastReader scan = new FastReader();
        String str1 = scan.next();
        String str2 = scan.next();
        for(long i = 2; i <= 36; i++) lim[(int)i] = MX/i;
        int aa = -1, bb = -1;
        for(int a = 2; a <= 36; a++){
            long v1 = calc(str1, a);
            if(v1 == -1L) continue;
            for(int b = 2; b <= 36; b++){
                if(a==b) continue;
                long v2 = calc(str2, b);
                //out.println(a + " " + v1 + " " + b + " " + v2);
                if(v1 == v2){
                    if(aa != -1){
                        out.println("Multiple");
                        out.close();
                        return;
                    }
                    aa = a; bb = b;
                }
            }
        }
        if(aa == -1) out.println("Impossible");
        else out.println(calc(str1, aa) + " " + aa + " " + bb);
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