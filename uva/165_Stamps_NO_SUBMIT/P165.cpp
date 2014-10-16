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
const int maxn = 200;
int A[10];
int B[10];
int C[maxn];
int h,k;
int ans=-INF;
int memo[10][maxn];

void f(int cur, int value) {
   C[value] = 1;
   if(memo[cur][value]!=-1) return;
   memo[cur][value] = 1;
	if(cur==h) return;
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < k; ++j) {
         if(memo[cur+1][value+A[j]]==-1)
             f(cur+1,value+A[j]);
		}
	}
}

void dfs(int cur) {
	if(cur==k) {
		memset(memo,-1,sizeof(memo));
		memset(C,0,sizeof(C));
		f(0,0);
		int t; 
		for(t = 1; t <= maxn; ++t) if(!C[t]) break;
		if(t-1 > ans) {
			ans = t-1;
			for(int i = 0; i < k; ++i) B[i] = A[i];
		}
	} else {
		for(int i = cur; i <= 35; ++i) {
			A[cur] = i;
			dfs(cur+1);
		}
	}
}

int main(int argc, char *argv[]) {
	while(scanf("%d%d",&h,&k)==2) {
		if(h==0||k==0) break;
		ans=-INF;
		memset(A,-1,sizeof(A));
		A[0]=1;
		dfs(1);
		printf("   ");
		for(int i = 0; i < k; ++i)
			printf("%d ",B[i]);
		printf("->%*d\n",3,ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

