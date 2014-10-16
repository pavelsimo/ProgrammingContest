package google.gcj2010.round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Rotate {

    private static boolean DEBUG = false;
    
    private static char[][] B;
   
    private static boolean joink(char P, int K) {
        int c;
        
        // rows
        for (int i = 0; i < B.length; i++) {
            c = 0;
            for (int j = 0; j < B.length; j++) {
                if (B[i][j] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
        }
        // cols
        for (int i = 0; i < B.length; i++) {
            c = 0;
            for (int j = 0; j < B.length; j++) {
                if (B[j][i] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
        }
        //diagonals
        for (int i = 0; i < B.length; i++) {
            c = 0;
            for (int j = 0; j < B.length - i; j++) {
                if (B[i + j][j] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
            c = 0;
            for (int j = 0; j < B.length - i; j++) {
                if (B[i + j][B.length - j - 1] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
            c = 0;
            for (int j = 0; j < B.length - i; j++) {
                if (B[j][i + j] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
            c = 0;
            for (int j = 0; j < B.length - i; j++) {
                if (B[j][B.length - i - 1] == P)
                    c++;
                else
                    c = 0;
                if (c == K)
                    return true;
            }
        }
        return false;
    }

    private static void solve(String file) throws Exception {
        
        BufferedReader f = new BufferedReader(new FileReader(file + ".in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

        int T = Integer.parseInt(f.readLine());

        for (int i = 0; i < T; i++) {
            String[] s = f.readLine().split(" ");
            int N = Integer.parseInt(s[0]);
            int K = Integer.parseInt(s[1]);
            if (DEBUG)
                System.out.println(N + " " + K);
            
            B = new char[N][N];
            for (int j = 0; j < N; j++) {
                String line = f.readLine().replaceAll("\\.", "");
                for (int k = 0; k < N - line.length(); k++)
                    B[j][k] = '.';
                for (int k = 0; k < line.length(); k++)
                    B[j][N - k - 1] = line.charAt(line.length() - k - 1);
            }
            if (DEBUG) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++)
                        System.out.print(B[j][k]);
                    System.out.println();
                }
            }
            
            String winner = "Neither";
            boolean red = joink('R', K);
            boolean blue = joink('B', K);
            if (red && blue)
                winner = "Both";
            else if (red)
                winner = "Red";
            else if (blue)
                winner = "Blue";

            out.println("Case #" + (i+1) + ": " + winner);
            System.out.println("Case #" + (i+1) + ": " + winner);
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        
        //String file = "A-test";
        String file = "A-small-attempt0";
        //String file = "A-large";

        solve(file);
    }
}
