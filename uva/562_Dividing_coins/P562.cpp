/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  562  C++  "DP" */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 102;
const int maxm = 50002;
int memo[maxn][maxm];
int v[maxn];
int N;

int d(int cur, int c) {
	if(cur==N) return c;
	if(memo[cur][c] >= 0) return memo[cur][c];
	return memo[cur][c] = min(d(cur+1,abs(c+v[cur])),d(cur+1,abs(c-v[cur])));
}

int main() {
	int TC;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));	
		scanf("%d",&N);
		for(int i = 0; i < N; ++i) scanf("%d",&v[i]);
		printf("%d\n",d(0,0));
	}
	return 0;
}
