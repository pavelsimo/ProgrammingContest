/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ COMDIV C++ "Math, Number Theory" */
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

const int MAXN = 1000001;
vector<int> D[MAXN];

void sieve() {
   for(int i = 1; i < MAXN; ++i)
      D[i].push_back(1);
   for(int i = 2; i < MAXN; ++i)
      for(int j = i; j < MAXN; j+=i)
         D[j].push_back(i);  
}

int main(int argc, char *argv[]) {
   sieve();
   int TC, a, b, res;
   vector<int> T(250);
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&a,&b);
      res = set_intersection(all(D[a]),all(D[b]),T.begin())-T.begin();
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
