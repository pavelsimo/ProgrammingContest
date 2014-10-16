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

const int MAXN = 10020;
const int MOD = 1000000007;
int N, DS[40];
char S[10020];
int seen[MAXN][5][40], memo[MAXN][5][40], tc;

int go(int n, int len, int sum) {
   if(S[n] == '\0' || len == 4) return DS[sum];
   if(seen[n][len][sum] == tc) return memo[n][len][sum];
   int res = 0;
   if(len <= 3) {
      res += go(n + 1, len + 1, sum + S[n] - '0');
      if(res >= MOD) res -= MOD;
   }
   res += go(n + 1, len, sum);
   if(res >= MOD) res -= MOD;
   seen[n][len][sum] = tc;
   return memo[n][len][sum] = res;
}

int main(int argc, char *argv[]) {
   for(int i = 0; i < 40; ++i) 
      DS[i] = sum_digits(i) == 9;
   int TC;
   gets(S);
   sscanf(S,"%d",&TC);
   for(int t = 1; t <= TC; ++t) {
      tc = t;
      gets(S);
      printf("%d\n",go(0, 0, 0));
   }
   return 0;
}

