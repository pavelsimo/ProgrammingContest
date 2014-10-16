/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  607  C++  "DP" */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int INF = 1000000;
const int maxn = 1010;
const int maxm = 510;
int topic[maxn];
int memo[maxn][maxn];
int N, L, C;


int d(int cur, int minutes) {
	
	
	
}

int main(int argc, char *argv[]) {
	int TC = 0;
	while(scanf("%d",&N)==1) {
		if(N==0)break;
		if(TC > 0) putchar('\n');
		scanf("%d%d",&L,&C);
		for(int i = 0; i < N; ++i) 
			scanf("%d",&topic[i]);
		printf("Case %d:\n",++TC);
		printf("Minimum number of lectures: %d\n",d());
		printf("Total dissatisfaction index: %d\n",0);
	}
	
	
	return 0;
}
