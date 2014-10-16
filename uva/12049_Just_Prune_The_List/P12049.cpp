/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12049  C++  "Ad Hoc" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#ifdef __GNUC__
#if (__GNUC__ <= 2)
  #include <hash_map>
  using std::hash_map;
#else
  #include <ext/hash_map>
  using __gnu_cxx::hash_map;
#endif
#else
//#elif _WIN32
  #include "stl_hash.h"
  using std::hash_map;
#endif
 
int A[10002], B[10002];
hash_map<int,int> freq1, freq2;

int main(int argc, char *argv[]) {
   int TC, N, M, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      freq1.clear();
      freq2.clear();
      scanf("%d%d",&N,&M);
      for(int i = 0; i < N; ++i) {
         scanf("%d",&A[i]);
         freq1[A[i]]++;
      }
      for(int i = 0; i < M; ++i) {
         scanf("%d",&B[i]);
         freq2[B[i]]++;
      }
      res = 0;
      for(int i = 0; i < N; ++i) {
         res+=abs(freq1[A[i]]-freq2[A[i]]);
         freq1[A[i]] = 0;
         freq2[A[i]] = 0;
      }
      for(int i = 0; i < M; ++i) {
         res+=abs(freq1[B[i]]-freq2[B[i]]);
         freq1[B[i]] = 0;
         freq2[B[i]] = 0;
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
