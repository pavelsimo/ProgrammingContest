/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11076  C++  "Ad Hoc, Brute Force" */
#include <algorithm>
#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

typedef long long llong;

#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int A[16], pow10[] = {1,10,100,1000,10000,100000,1000000,10000000};
map<int,int> freq;


int main(int argc, char *argv[]) {
   int N;
   llong sum;
   while(1 == scanf("%d",&N)) {
      puts("");
      freq.clear();
      if(!N) break;
      for(int i = 0; i < N; ++i)
         scanf("%d",&A[i]);
      sort(A, A + N);
      sum = 0LL;
      do {
         llong m = 0;
         for(int i = 0; i < N; ++i) {
            int x = pow10[N-i-1] * A[i];
            freq[x]++;
            m = m*10LL + A[i];
         }
         printf("%lld\n",m);
         sum += m;
      } while(next_permutation(A, A + N));
      puts("");
      foreach(it,freq)
         printf("%d - %d\n",it->first, it->second);
      printf("%lld\n",sum);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

