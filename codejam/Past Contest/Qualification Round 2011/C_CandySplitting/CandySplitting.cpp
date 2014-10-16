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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

int N;
int C[1010];

int doit() {  
   sort(C,C+N);
   int sum = C[0];
   int res = 0;
   for(int i = 1; i < N; ++i) {
      sum^=C[i];
      res+=C[i];
   }
   return sum==0 ? res: -1;
}

int main() {
   int TC, res;
   scanf("%d",&TC);
   int tc = 1;
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i) 
         scanf("%d",C+i);
      res = doit();
      if(res >= 0)
         printf("Case #%d: %d\n",tc++,res);
      else
         printf("Case #%d: NO\n",tc++);
   }
   return 0;
}
