/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  910  C++  "Graph Theory, DP" */
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
#include <list>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

int adj[30][2];
char buf[128];
int memo[32][28];
int n;
int m;
set<int> F;

int d(int cur, int v) {
   if(cur==m) 
       return F.count(v) > 0? 1: 0;
	if(memo[cur][v]>=0) return memo[cur][v];
   return memo[cur][v] = d(cur+1,adj[v][0])+d(cur+1,adj[v][1]);
}

int main(int argc, char *argv[]) {
	int k;
	char state, path1, path2, type;
	while(gets(buf)) {
		memset(adj,0,sizeof(adj));
		memset(memo,-1,sizeof(memo));
		F.clear();
		k=0;
		sscanf(buf,"%d",&n);
		for(int i = 0; i < n; ++i) {
			gets(buf);
			sscanf(buf,"%c %c %c %c",&state,&path1,&path2,&type);
			adj[state-'A'+1][0] = path1-'A'+1;
			adj[state-'A'+1][1] = path2-'A'+1;
			if(type=='x') F.insert(state-'A'+1);
		}
		gets(buf);
		sscanf(buf,"%d",&m);
		printf("%d\n",d(0,1));
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

