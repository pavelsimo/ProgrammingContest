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

int main(int argc, char *argv[]) {
   int TC, N, M, res, x;
   scanf("%d",&TC);
   while(TC-- > 0) {
      hash_map<int,int> freq;
      scanf("%d%d",&N,&M);
      for(int i = 0; i < N; ++i) {
         scanf("%d",&x);
         freq[x]++;
      }
      for(int i = 0; i < M; ++i) {
         scanf("%d",&x);
         freq[x]--;
      }
      res = 0;
      foreach(it,freq)
         res+=abs(it->second);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
