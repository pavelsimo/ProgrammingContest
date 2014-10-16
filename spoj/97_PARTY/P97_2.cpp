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
int memo[N][M]; // state(budget,party) = fun
int fun[M];
int price[M];
int nbudget, nparty;
int INF = 10000000;

int d(int budget, int party) {
	if(budget<0) return -INF;
	if(party==nparty)return 0;
	int &ans = memo[budget][party];
	if(ans>=0) return ans;
	ans = max(d(budget,party+1),d(budget-price[party],party+1)+fun[party]);
	return ans;
}

int main(int argc, char *argv[]) {
	while(scanf("%d%d",&nbudget,&nparty)==2) {
	   memset(memo,-1,sizeof(memo));
		if(nbudget==0||nparty==0)break;
		for(int i=0; i < nparty; ++i)
			scanf("%d%d",&price[i],&fun[i]);
		cout << d(nbudget,0) << endl;
	}
	return 0;
}


