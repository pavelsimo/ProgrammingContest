/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  429  C++  "Graph Theory, BFS" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <utility>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef pair<int,int> node;
typedef vector<int> vi;
typedef vector<string> vs;

const int maxn = 210;
vs dictionary;
vi adj[maxn];
map<string,int> idx;

int bfs(int src, int dst) {
	set<int> vis;
	queue<node> q;
	q.push(make_pair(src,0));
	vis.insert(src);
	while(!q.empty()) {
		node s = q.front();
		q.pop();
		if(s.first == dst) return s.second;
		int u = s.first;
		for(int v = 0; v < adj[u].size(); ++v) {
			if(vis.count(adj[u][v])==0) {
				vis.insert(adj[u][v]);
				q.push(make_pair(adj[u][v],s.second+1));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int TC, done=0;
	string buf;
	string src, dst;
	scanf("%d\n",&TC);
	for(int tc=0; tc < TC; ++tc) {
		if(tc!=0) putchar('\n');
		done = 0;
		while(getline(cin,buf)) {
			if(buf[0]=='*') {
				memset(adj,0,sizeof(adj));
				for(int i = 0; i < dictionary.size(); ++i) {
               idx[dictionary[i]] = i;
					for(int j = i+1; j < dictionary.size(); ++j) {
						if(dictionary[i].size() != dictionary[j].size()) continue;
						int cnt = 0;
						string a = dictionary[i];
						string b = dictionary[j];
						for(int k = 0; k < dictionary[i].size(); ++k) {
							if(a[k]!=b[k]) cnt++;
							if(cnt > 1) break;
						}
						if(cnt==1) {
                      adj[i].push_back(j);
                      adj[j].push_back(i);
                  }
					}
				}
				while(getline(cin,buf)) {
					if(buf.size()==0) break;
					istringstream ncin(buf);
					getline(ncin,src,' ');
					getline(ncin,dst,' ');
					done=1;
					printf("%s %s %d\n",src.c_str(),dst.c_str(),bfs(idx[src],idx[dst]));
				}
				dictionary.clear();
				idx.clear();
				if(done) break;
			}
			if(done) break;
			dictionary.push_back(buf);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
