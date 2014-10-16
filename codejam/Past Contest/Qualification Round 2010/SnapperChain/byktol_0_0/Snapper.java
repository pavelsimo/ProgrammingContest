
import java.io.*;
import java.util.StringTokenizer;

/**
 * @author byktol
 */
public class Snapper {
  static String input = "A-small.in";
  static String output = "A-small.out";

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader(input));
    BufferedWriter bw = new BufferedWriter(new FileWriter(output));

    int T = Integer.parseInt(br.readLine());
    for (int i = 1 ; i <= T; i++) {
      String s = br.readLine();
      StringTokenizer st = new StringTokenizer(s, " ");
      double n = Double.parseDouble(st.nextToken());
      Double k = Double.valueOf(st.nextToken());

      Double max = Math.pow(2.0, n);
      long lmax = max.longValue();
      long lk = k.longValue();

      bw.append("Case #");
      bw.append(String.valueOf(i));
      bw.append(lk % lmax == lmax -1? ": ON" : ": OFF");
      bw.append("\n");
    }
    br.close();
    bw.append("\n");
    bw.close();
  }

}
