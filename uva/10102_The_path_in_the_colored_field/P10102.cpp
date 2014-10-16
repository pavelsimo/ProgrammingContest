/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10102  C++  "Graph Theory, BFS" */
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
#include <queue>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

typedef pair<int,int> ii;
typedef vector<ii> vii;
const int maxn = 1024, INF = 10000000;
char buf[maxn];
char B[maxn][maxn];
int n, D[maxn][maxn];
vii src, dst;

int doit() {
	int ans = 0;
	for(int i = 0; i < src.size(); ++i) {
		int cost=INF;
		int sx = src[i].first;
		int sy = src[i].second;
		for(int j = 0; j < dst.size(); ++j) {
			int tx = dst[j].first;
			int ty = dst[j].second;
			cost=min(cost,abs(sx-tx)+abs(sy-ty));
		}
		ans=max(ans,cost);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	while(gets(buf)) {
		if(sscanf(buf,"%d",&n)!=1) break;
		src.clear();
		dst.clear();
		for(int i = 0; i < n; ++i) {
		   gets(B[i]);
			for(int j = 0; j < n; ++j) {
				if(B[i][j]=='1') src.push_back(ii(i,j));
				if(B[i][j]=='3') dst.push_back(ii(i,j));
			}
		}
		printf("%d\n",doit());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

