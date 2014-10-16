/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10150 C++  "Graph Theory, BFS" */
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

const int maxn = 25150;
vector<string> dictionary;
vector<int> adj[maxn];
int parent[maxn];
map<string,int> idx;
stack<string> out;

int bfs(int src, int dst) {
	set<int> vis;
	queue<int> q;
	q.push(src);
	vis.insert(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		if(u==dst) return 1;
		for(int v = 0; v < adj[u].size(); ++v) {
			if(vis.count(adj[u][v])==0) {
				parent[adj[u][v]] = u;
				q.push(adj[u][v]);
				vis.insert(adj[u][v]);
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	string s;
	string src, dst;
	int k=0;
	while(getline(cin,s)) {
		if(s.size()==0) {
			memset(parent,0,sizeof(parent));
			int tc=0;
			while(getline(cin,s)) {
				if(tc++!=0) putchar('\n');
				istringstream ncin(s);
				getline(ncin,src,' ');
				getline(ncin,dst,' ');
				int _src = idx[src]; 
				int _dst = idx[dst];
				if(bfs(_src,_dst)) {
					int cur = _dst;
					while(cur!=_src) {
						out.push(dictionary[cur]);
						cur = parent[cur];
					}
					printf("%s\n",src.c_str());
					while(!out.empty()) {
						printf("%s\n",out.top().c_str());
						out.pop();
					}				
				} else {
					printf("No solution.\n");
				}
			}
			k=0;
		} else {
			idx[s] = k++;
			dictionary.push_back(s);
			for(int i = dictionary.size()-2; i >= 0; --i) {
				if(dictionary[i].size()!=s.size()) continue;
				int cnt=0;
				string t = dictionary[i];
				for(int j = 0; j < s.size(); ++j) {
					if(t[j]!=s[j]) cnt++;
					if(cnt>1) break;
				}
				if(cnt==1) {
					adj[dictionary.size()-1].push_back(i);
					adj[i].push_back(dictionary.size()-1);
				}
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

