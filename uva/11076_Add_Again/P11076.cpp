/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11076  C++  "Math, Permutations" */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ullong;

const int MAXN = 14;

const ullong fact[] = {1,1,2,6,24,120,720,5040,40320,362880,
                        3628800,39916800,479001600};
const ullong P[] = {0,1,11,111,1111,11111,111111,1111111,11111111,
                     111111111,1111111111,11111111111,111111111111};
                     
int N, A[MAXN], freq[MAXN], seen[MAXN];

int main(int argc, char *argv[]) {
   ullong sum;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      memset(seen, 0, sizeof(seen));
      memset(freq, 0, sizeof(freq));
      for(int i = 0; i < N; ++i) {
         scanf("%d",&A[i]);
         freq[A[i]]++;
      }
      sum = 0LL;
      for(int i = 0; i < N; ++i) {
         if(seen[A[i]]) continue;
         seen[A[i]] = 1;
         ullong f = fact[N - 1];
         for(int j = 0; j <= 9; ++j) {
            int ind = freq[j] - (A[i] == j);
            f /= fact[ind];
         }
         sum += f * P[N] * A[i];
      }
      printf("%llu\n",sum);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

