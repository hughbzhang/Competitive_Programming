package Solved;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
ID:             liluyan1
LANG:   JAVA
TASK:   hamming
*/
public class test {
        public static void main(String[] args) throws IOException {
                BufferedReader f = new BufferedReader(new FileReader("hamming.in"));
                PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
                                "hamming.out")));
                new test().solve(f, out);
                out.close();
                System.exit(0);
        }
        
        private void solve(BufferedReader f, PrintWriter out) throws IOException {
                int[] a = read(f, 3);
                int N = a[0], B = a[1], D = a[2];
                
                a = new int[N];
                a[0] = 0;
                int start = 1;
                for (int i=1; i<N; i++) {
                        for (int j=start; j<(1<<B); j++) {
                                boolean valid = true;
                                for (int k=0; k<i; k++) {
                                        if (distance(a[k], j) < D) {
                                                valid = false;
                                                break;
                                        }
                                }
                                if (valid) {
                                        a[i] = j;
                                        break;
                                }
                        }
                }
                
                for (int i=0; i<N; i++) {
                        if (i%10 == 0 && i>0) out.println();
                        out.print(i%10==0? a[i] : " " + a[i]);
                }
                out.println();
        }
        
        private int distance(int a, int b) {
                int c = a ^ b;
                int count = 0;
                while (c > 0) {
                        count++;
                        c = c & (c-1);
                }
                return count;
        }
        
        public int read(BufferedReader f) throws IOException {
                return Integer.parseInt(f.readLine());
        }
        
        public int[] read(BufferedReader f, int N) throws IOException {
                String[] t = f.readLine().split(" ");
                int[] a = new int[N];
                for (int i=0; i<N; i++) {
                        a[i] = Integer.parseInt(t[i]);
                }
                return a;
        }
}