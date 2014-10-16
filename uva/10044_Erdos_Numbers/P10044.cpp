/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10044  C++  "BFS" */
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

const int maxn = 10010;
vector<int> adj[maxn];
int D[maxn];

void bfs(int src) {
	queue<int> Q;
	Q.push(src);
	D[src]=0;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if(D[nxt]==-1) {
				D[nxt] = D[cur] + 1;
				Q.push(nxt);
			}
		}
	}
}

void ltrim(string &s) {   
	size_t begin = s.find_first_not_of(" \t");
	if(begin!=string::npos) s = s.substr(begin,s.size());
}

int main(int argc, char *argv[]) {
	int TC, tc=0, n, m, iid;
	string buf, token, src="Erdos, P.";
	map<string,int> id;
	getline(cin,buf);
	istringstream(buf) >> TC;
	while(TC-- > 0) {
      memset(D,-1,sizeof(D));
		for(int i = 0; i < maxn; ++i) adj[i].clear();
		id.clear();
		getline(cin,buf);
		istringstream(buf) >> n >> m;
		iid=1;
		id[src]=0;
		for(int i = 0; i < n; ++i) {
			getline(cin,buf);
			vector<string> vs;
			int fb, fe, lb, le;
			for(fb=0,fe=0,lb=0,le=0; buf[fe]!=':' && buf[le]!=':' ; ) {
				fb=buf.find_first_not_of(",",le);
				fe=buf.find_first_of(",:",fb);
				lb=buf.find_first_not_of(",",fe);
				le=buf.find_first_of(",:",lb);
				if(fb==string::npos || fe==string::npos || lb==string::npos || le==string::npos) break;
				string author = buf.substr(fb,fe-fb) + "," + buf.substr(lb,le-lb);
				ltrim(author);
				vs.push_back(author);
			}
			for(int j = 0; j < vs.size(); ++j)
				if(id.count(vs[j])==0) 
					id[vs[j]]=iid++;
			for(int v = 0; v < vs.size()-1; ++v) {
				for(int u = v+1; u < vs.size(); ++u) {
					adj[id[vs[v]]].push_back(id[vs[u]]);
					adj[id[vs[u]]].push_back(id[vs[v]]);
				}
			}
			vs.clear();
		}
		printf("Scenario %d\n",++tc);
		bfs(0);
		for(int i = 0; i < m; ++i) {
			getline(cin,buf);
			ltrim(buf);
			if(id.count(buf)==0 || D[id[buf]]==-1) printf("%s infinity\n",buf.c_str());
			else printf("%s %d\n",buf.c_str(),D[id[buf]]);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

