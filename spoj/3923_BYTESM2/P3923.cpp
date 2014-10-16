#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 110;
const int maxm = 110;
int memo[maxn][maxm];
int C[maxn][maxm];
int n, m;

int d(int i, int j) {
	if(i==n+1||j>m||j<0) return 0;
	if(memo[i][j]>=0) return memo[i][j];
	return memo[i][j] = C[i][j] + max(d(i+1,j-1),max(d(i+1,j),d(i+1,j+1))); 
}

int main(int argc, char *argv[]) {	
	int TC, ans;
	scanf("%d",&TC);
	while(TC-- >0) {
		scanf("%d%d",&n,&m);
		memset(C,0,sizeof(C));
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j)
				scanf("%d",&C[i][j]);
		}
		ans=0;
		for(int i = 1; i <= m; ++i) {
			memset(memo,-1,sizeof(memo));
			ans=max(ans,d(1,i));
		}
		printf("%d\n",ans);
	}
	return 0;
}
