#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sum_digits(int n) {
   while(n > 10) {
      int x = n;
      int sum = 0;
      while(x > 0) {
         sum += x % 10;
         x/=10;
      }      
      n = sum;
   }
   return n;
}

const int MAXN = 10020, MOD = 1000000007;
char S[10020];

int N, SD[40], DP[MAXN][5][40];

int main(int argc, char *argv[]) {
   for(int i = 0; i < 40; ++i) 
      SD[i] = sum_digits(i) == 9;
   int TC;
   gets(S);
   sscanf(S,"%d",&TC);
   while(TC-- > 0) {
      gets(S + 1);
      int N = strlen(S);
      
      // (n, len, sum) = # count of subsequences where the sum of digits is equal to 9 
      memset(DP, 0, sizeof(DP));
      for(int sum = 0; sum <= 36; ++sum) {
         for(int len = 1; len <= 4; ++len) {
            for(int i = 1; i <= N-1; ++i) {
               int x = S[i] - '0';
               DP[i][len][sum] += DP[i - 1][len][sum];
               if(sum >= x)
                  DP[i][len][sum] += DP[i - 1][len - 1][sum - x] + SD[sum];
               if(DP[i][len][sum] >= MOD) DP[i][len][sum] -= MOD;
               printf("DP[%d][%d][%d] = %d\n",i,len,sum,DP[i][len][sum]);
            }
         }
      }
      printf("%d\n",DP[N-1][4][36]);
   }
   return 0;
}

