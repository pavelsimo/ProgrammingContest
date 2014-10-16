#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int INF = 1000000;
const int maxn = 102;
int n;
int A[maxn];
int mix[maxn][maxn];
int cost[maxn][maxn];

int go(int n) {
	for(int i = 1; i <= n; ++i) {
		mix[i][i] = A[i];
		cost[i][i] = 0;
	}
	for(int d = 1; d < n; ++d) {
		for(int j=1; j <= n-d; ++j) {
			int start = j;
			int end = j+d;
			cost[start][end] = INF;
			for(int k = start; k < end; ++k) {
				int ncost = cost[start][k]+cost[k+1][end]+(mix[start][k]*mix[k+1][end]);
				if ( ncost < cost[start][end] ) {
					cost[start][end] = ncost;
					mix[start][end] = (mix[start][k]+mix[k+1][end])%100;
				}
			}
		}	
	}
	return cost[1][n];
}

int main(int argc, char *argv[]) {
	while(scanf("%d",&n)==1) {
		memset(mix,0,sizeof(mix));
		memset(A,0,sizeof(A));
		for(int i = 1; i <= n; ++i)
			scanf("%d",&A[i]);	
		cout << go(n) << endl;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

