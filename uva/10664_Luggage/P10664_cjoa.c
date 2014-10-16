/* @JUDGE_ID: 1131EP  10664  C  "Dynamic Programming" */
#include <stdio.h>
#include <string.h>

int DP[204];
char line[1024];

int main(int argc, char* argv[]) {
   int TC;
   gets(line);
   sscanf(line, "%d", &TC);
   while (TC-- > 0) {
      int sumw, i, W;
      char *p;
      memset(DP, 0, sizeof(DP));
      DP[0] = 1;
      sumw = 0;
      gets(line);
      for (p = strtok(line, " "); p; p = strtok(NULL, " ")) {
         W = atol(p);
         for (i = sumw; i >= 0; --i)
            if (DP[i])
               DP[ i+W ] = 1;
         sumw += W;
      }
      puts((sumw & 1) == 0 && DP[sumw/2] ? "YES" : "NO");
   }
   return 0;
}
