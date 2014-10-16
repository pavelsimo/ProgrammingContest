/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11545  C++  "DP, Graph Theory, BFS" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int INF = 10000000;
char s[1010];
int memo[1010][25][18];

int d(int cur, int time, int maxrt) {
	if(maxrt>16) return INF;
	if(s[cur]=='*') if(time >= 18 || time <=6) return INF;
	if(s[cur]=='D') return 0;
	if(memo[cur][time][maxrt] >= 0) return memo[cur][time][maxrt];
	return memo[cur][time][maxrt] = min(d(cur+1,(time+1)%24,maxrt+1)+1, d(cur+1,(time+9)%24,1)+9);
}

int main(int argc, char *argv[]) {
	int TC, ans;
	gets(s);
	sscanf(s,"%d",&TC);
	for(int tc=1; tc<=TC; ++tc) {
		memset(memo,-1,sizeof(memo));
		gets(s);
		ans=d(0,6,0);
		printf("Case #%d: %d\n",tc,ans>=INF?-1:ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
