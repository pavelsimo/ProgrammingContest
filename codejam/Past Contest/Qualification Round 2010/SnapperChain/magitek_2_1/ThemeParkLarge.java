package google.gcj2010.qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ThemeParkLarge {

    private static int R;
    private static long k;
    private static int N;
    private static long[] G;
    private static long[] GC;
    private static long[] GE;

    private static long[] next(int i) {
        long[] next = {0, 0}; 
        long K = 0;
        for (int j = 0; j < N; j++) {
            if (K + G[i] > k)
                break;
            K += G[i];
            i = (i + 1) % N;
        }
        next[0] = i; // next index
        next[1] = K; // number of people
        return next;
    }
    
    private static long euros(int i, int R) {
        long K = 0;
        int r = 0;
        while (r < R) {
            long next[] = next(i);
            i = (int) next[0];
            K += next[1];
            r++;
        }
        return K;
    }

    private static long euros() {
        int I = 0;
        long C = 0;
        long E = 0;
        long C_, E_;
        GC[0] = 0;
        GE[0] = 0;

        while (true) {
            long next[] = next(I);
            I = (int) next[0];
            E += next[1];
            C++;
            if (GC[I] == -1) {
                GC[I] = C;
                GE[I] = E;
            }
            else {
                C_ = C - GC[I];
                E_ = E - GE[I];
                break;
            }
        }
        
        if (C > R) {
            E = euros(0, R);
        }
        else if (C < R) {
            E += ((R - C) / C_) * E_;
            C += ((R - C) / C_) * C_;
            if (C < R) {
                E += euros(I, (int) (R - C));
            }
        }
        return E;
    }
    
    private static void parse(BufferedReader f) throws Exception {
        String[] s = f.readLine().split(" ");
        R = Integer.parseInt(s[0]);
        k = Long.parseLong(s[1]);
        N = Integer.parseInt(s[2]);
        s = f.readLine().split(" ");
        G = new long[N];
        GC = new long[N];
        GE = new long[N];
        for (int j = 0; j < N; j++) {
            G[j] = Long.parseLong(s[j]);
            GC[j] = -1;
            GE[j] = 0;
        }
    }
    private static void solve(String file) throws Exception {
        
        BufferedReader f = new BufferedReader(new FileReader(file + ".in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

        int T = Integer.parseInt(f.readLine());
        long E;

        for (int i = 0; i < T; i++) {
            parse(f);
            E = euros();
            out.println("Case #" + (i+1) + ": " + E);
            System.out.println("Case #" + (i+1) + ": " + E);
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        
        //String file = "C-test";
        //String file = "C-small-attempt0";
        String file = "C-large";

        solve(file);
    }
}
