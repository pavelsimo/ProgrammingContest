/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  406  C++  "Number Theory" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 1500;
int prime[maxn+10];

void sieve(int n) {
   for(int i = 0; i <= n; ++i) prime[i] = 1;
   prime[0]=0;
   prime[1]=0;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=0;
}

int main(int argc, char *argv[]) {
	sieve(maxn);
	prime[1] = 1;
	int n, c, pos, lb, ub;
	vector<int> cut;
	while(scanf("%d%d",&n,&c)==2) {
		for(int i = 1; i <= n; ++i)
			if(prime[i]) 
				cut.push_back(i);
		pos = cut.size()/2;		
		printf("%d %d: ",n,c);
		if(2*c >= n) {
        lb = 0;
        ub = cut.size();
      } else if(cut.size()%2==0) {
		  lb = pos-c < 0? 0: pos-c;
        ub = pos+c >= cut.size() ? cut.size(): pos+c;
		} else {
		  lb = pos-c+1 < 0? 0: pos-c+1;
        ub = pos+c >= cut.size() ? cut.size(): pos+c;			
		}
		for(int i = lb; i < ub; ++i) {
			if(i!=lb) putchar(' ');
			printf("%d",cut[i]);
		}
		putchar('\n');
		putchar('\n');
		cut.clear();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
