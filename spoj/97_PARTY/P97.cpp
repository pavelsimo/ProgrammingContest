#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <bitset>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int N=510;
const int M=110;
int DP[M][N];
int W[M];
int V[M];
int nbudget, nparty;
int INF = 10000000;

int doit() {
   for(int i = 1; i <= nparty; ++i) {
      for(int j = 0; j <= nbudget; ++j) {
          DP[i][j] = (i==1 ? 0: DP[i-1][j]);
          if(j >= W[i]) DP[i][j] = max(DP[i][j],DP[i-1][j-W[i]]+V[i]);
      }
   }
   return DP[nparty][nbudget];
}

int main(int argc, char *argv[]) {
	while(scanf("%d%d",&nbudget,&nparty)==2) {
	   memset(DP,0,sizeof(DP));
		if(nbudget==0||nparty==0)break;
		for(int i=1; i <= nparty; ++i)
			scanf("%d%d",&W[i],&V[i]);
		int fun = doit();
		int cost = 0;
		for(int i = 0; i <= nbudget; ++i) {
          if(DP[nparty][i]==fun) {
              cost= i; 
              break;
          }
      }
      printf("%d %d\n",cost,fun);
	}
	return 0;
}


