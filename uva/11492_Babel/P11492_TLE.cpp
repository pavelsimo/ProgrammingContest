/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11492  C++  "Graph Theory, Shortest Path" */
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

int N;
const int maxn = 2010;
const int INF = 2147483630;
string buf, O, T, L1, L2, P;
vector<string> W;
vector<int> S;
vector<string> adj[maxn];
map<string,int> id;
int D[maxn];
vector<string> I1,I2;

struct node {
	int d;
	string s;
	node(int _d=0,string _s="") {
		s=_s;
		d=_d;
	}
	bool operator< (const node &T) const {
		if(d!=T.d) return T.d < d;
		return false;
	}
};

int dijkstra() {
	priority_queue<node,vector<node> > Q;
	for(int i = 0; i < S.size(); ++i) {
		Q.push(node(W[S[i]].size(),W[S[i]]));
		D[S[i]] = W[S[i]].size();
	}
	while(!Q.empty()) {
		node cur = Q.top(); Q.pop();
		int d = cur.d;
		string word = cur.s;
		int v = id[word];
		if(I1[v]==T || I2[v]==T) return d;
		if(d <= D[v]) {
			for(int i = 0; i < adj[v].size(); ++i) {
				string nxt = adj[v][i];
				int cost = nxt.size();
				int u = id[nxt];
				if(D[v]+cost < D[u]) {
					D[u] = D[v]+cost;
					Q.push(node(D[u],nxt));
				}
			}				
		}
	}
	return -1;
}


int main(int argc, char *argv[]) {
	int ans;
	while(getline(cin,buf)) {
		sscanf(buf.c_str(),"%d",&N);
		if(N==0) break;		
		W.clear();
		S.clear();
		id.clear();
		I1.clear();
		I2.clear();
		for(int i = 0; i <= N; ++i) {
			adj[i].clear();
			D[i]=INF;
		}
		getline(cin,buf);
		istringstream ncin(buf);
		getline(ncin,O,' ');
		getline(ncin,T,' ');
		for(int i = 0; i < N; ++i) {
			getline(cin,buf);
			istringstream ncin2(buf);
			getline(ncin2,L1,' ');
			getline(ncin2,L2,' ');
			getline(ncin2,P,' ');
			if(L1==O) S.push_back(i);
			else if(L2==O) S.push_back(i);
			id[P] = i;
			I1.push_back(L1);
			I2.push_back(L2);
			W.push_back(P);
		}
		for(int i = 0; i < N-1; ++i) {
			for(int j = i+1; j < N; ++j) {
				if(W[i][0]!=W[j][0]) {
					if(I1[i]==I1[j]
					|| I1[i]==I2[j] 
					|| I2[i]==I1[j]
					|| I2[i]==I2[j] ) {
						adj[i].push_back(W[j]);
						adj[j].push_back(W[i]);
					}					
				}
			}
		}
		ans=dijkstra();
		if(ans>=0)printf("%d\n",ans);
		else puts("impossivel");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

