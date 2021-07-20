import java.io.*;
import java.util.*;

public class Main {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int Q, pid_cnt;
    static HashMap<String, Integer> name_map;
    static PriorityQueue<Integer>[] info;

    static void input() {
        Q = scan.nextInt();
        name_map = new HashMap<>();
        info = new PriorityQueue[100005];
    }

    static int get_pid(String name){
        if (!name_map.containsKey(name)){
            name_map.put(name, ++pid_cnt);
            info[pid_cnt] = new PriorityQueue<>(Comparator.reverseOrder());
        }
        return name_map.get(name);
    }

    static void pro() {
        long ans = 0;

        while (Q > 0) {
            Q--;
            int query = scan.nextInt();
            String name = scan.next();
            int pid = get_pid(name);
            if (query == 1) {
                int k = scan.nextInt();
                while (k > 0){
                    k --;
                    info[pid].add(scan.nextInt());
                }
            }else{
                int b = scan.nextInt();
                while (b > 0 && !info[pid].isEmpty()){
                    b--;
                    ans += info[pid].poll();
                }
            }
        }

        System.out.println(ans);
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