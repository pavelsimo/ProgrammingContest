/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  914  C++  "Prime Numbers, Segmented Sieve" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 1002;
vector<bool> P(MAXN);
vector<int> primes;

void sieve() {
   for(int i = 0; i < sz(P); ++i)
      P[i] = true; 
   P[0] = P[1] = false;
   for(int i = 2; i < MAXN; ++i) {
      if(P[i]) {
         primes.push_back(i);
         for(int j = i * i; j < MAXN; j+=i)
            P[j] = false;                    
      }
   }
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, lo, hi, prev, res, best;
   bool jchampion;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&lo,&hi);
      if(lo > hi) swap(lo,hi);
      vector<bool> S(hi - lo + 2, true);
      vector<int> freq(hi - lo + 2, 0);
      for(int i = 0; i < sz(primes); ++i) {
         int sq = primes[i]*primes[i];
         int m = lo % primes[i] == 0 ? max(sq,lo) : max(sq,lo + primes[i] - (lo%primes[i])); 
         for(int j = m; j >= lo && j <= hi; j+=primes[i])
            S[j-lo] = false;
      }
      prev = res = 0;
      best = -1;
      jchampion = false;
      for(int i = lo; i <= hi; ++i) {
         if(i < 2) continue;
         if(S[i-lo]) {
            if(prev) {
               freq[i-prev]++;
               if(freq[i-prev] == best) {
                  jchampion = false;
               } else if(freq[i-prev] > best) {
                  res = i - prev;
                  best = freq[i-prev];
                  jchampion = true;
               }
            }
            prev = i;
         }
      }
      if(!jchampion) puts("No jumping champion");
      else printf("The jumping champion is %d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
