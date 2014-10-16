/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  725  C++  "Brute Force, Simple Math" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int INF = 1000000;
const int maxn = 20001;
int n,m,t,DP[maxn];

int d(int k) {
   if(k<0) return -1; 
   if(DP[k]>0) return DP[k];
   DP[k] = max(d(k-n)+1,d(k-m)+1);
   return DP[k];
}

int main() {
   while(scanf("%d%d%d",&m,&n,&t)==3) {
      memset(DP,0,sizeof(DP));
      printf("%d\n",d(t));
      for(int i = 0; i <= 100; ++i)
          printf("DP[%d]=%d\n",i,DP[i]);
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
