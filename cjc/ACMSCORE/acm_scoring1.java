import java.io.*;
import java.util.Arrays;

public class acm_scoring1 {
   
   public static void main (String[] args) throws IOException {
      (new acm_scoring1()).Run();
   }
   
   void Run() throws IOException {
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      int TC = Integer.parseInt( in.readLine().trim() );
      for (int tc = 1; tc <= TC; ++tc) {
         String[] tok = in.readLine().split(" ");
         int D = Integer.parseInt(tok[0]);
         int P = Integer.parseInt(tok[1]);
         int[] T = new int[P];
         tok = in.readLine().split(" ");
         for (int i = 0; i < P; ++i)
            T[i] = Integer.parseInt(tok[i]);
         Arrays.sort(T);
         int nSolved = 0, nPenalty = 0;
         for (int i = 0, t = 5; i < P; ++i) {
            t += T[i];
            if (t > D) break;
            ++nSolved;
            nPenalty += t;
         }
         System.out.println("Case #" + tc + ": " + nSolved + " " + nPenalty);
      }
   }
}

