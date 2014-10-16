/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ TASKAGEN C++ "Ad Hoc" */
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

struct Program {
   int st, rt; 
   Program(int _st = 0, int _rt = 0) :
      st(_st), rt(_rt) {}
   bool operator<(const Program &T) const {
      if(rt!=T.rt) 
         return T.rt < rt;
      return T.rt > rt;
   }
};

Program a[55]; 

int main(int argc, char *argv[]) {
   int TC, N, res, time;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      for(int i = 0; i < N; ++i)
         scanf("%d",&a[i].st);
      for(int i = 0; i < N; ++i)
         scanf("%d",&a[i].rt);  
      sort(a,a+N);
      res = time = 0;
      for(int i = 0; i < N; ++i) {
         time += a[i].st;
         res = max(res, time + a[i].rt);
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
