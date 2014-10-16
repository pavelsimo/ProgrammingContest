/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MAJOR C++ "Ad Hoc" */
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
#define BITCOUNT(x) __builtin_popcount(x)

map<int,int> freq;

int main(int argc, char *argv[]) {
   int TC, N, x, M;
   scanf("%d",&TC);
   while(TC-- > 0) {
      freq.clear();
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) {
         scanf("%d",&x);
         freq[x]++;
      }
      M = N/2;
      bool found = false;
      foreach(it,freq) {
         if(it->second > M) {
            found = true;
            x = it->first;
            break;
         }
      }
      if(found) printf("YES %d\n",x);
      else puts("NO");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
