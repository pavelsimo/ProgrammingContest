/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10664  C++  "DP" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int maxn = 22;
const int maxm = 202;
int memo[maxn][maxm];
int v[maxn];
int N;

bool d(int cur, int c) {
	if(cur==N) return c==0;
	if(memo[cur][c]!=-1) return memo[cur][c];
	return memo[cur][c] = (d(cur+1,abs(c+v[cur])) || d(cur+1,abs(c-v[cur])));
}

int main() {
	int TC;
	string buf, token;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));	
		getline(cin,buf);
		istringstream ncin(buf);
		for(N=0; getline(ncin,token,' '); ++N)
			istringstream(token) >> v[N];
		printf("%s\n",d(0,0)?"YES":"NO");
	}
	return 0;
}
