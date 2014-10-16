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

struct Word {
	int id, lang1, lang2, size;
	char ch;
	Word(int _id, char _ch, int _size, int _lang1, int _lang2) {
		id=_id;
		size=_size;
		ch=_ch;
		lang1=_lang1;
		lang2=_lang2;
	}
};

struct Node {
	int id, d, lang1, lang2;
	char ch;
	Node(int _id, int _d, char _ch,int _lang1, int _lang2) {
		id=_id;
		d=_d;
		ch=_ch;
		lang1=_lang1;
		lang2=_lang2;
	}
	bool operator< (const Node &T) const {
		if(d!=T.d) return T.d < d;
		return false;
	}
};

int N;
const int maxn = 2010;
const int INF = 2147483630;
int D[maxn], isrc, idst;
vector<Word> adj[4020][26];
map<string,int> id_lang;
string buf, O, T, L1, L2, P;

int dijkstra() {
	priority_queue<Node,vector<Node> > Q;
	for(int i = 0; i <= N; ++i) D[i]=INF;
	for(int i = 0; i < 26; ++i) {
		for(int k = 0; k < adj[isrc][i].size(); ++k) {
			Word w = adj[isrc][i][k];
			Q.push(Node(w.id,w.size,w.ch,w.lang1,w.lang2));
			D[w.id] = w.size;
		}
	}
	while(!Q.empty()) {
		Node cur = Q.top(); Q.pop();
		int v = cur.id;
		int d = cur.d;
		int ch = cur.ch-'a';
		int lang1 = cur.lang1;
		int lang2 = cur.lang2;
		if(lang1==idst || lang2==idst) return d;
		if(d <= D[v]) {
			for(int k = 0; k <= 1; ++k) {
				for(int i = 0; i < 26; ++i) {
					if(ch==i) continue;
					int p = k ? lang2: lang1;
					for(int j = 0; j < adj[p][i].size(); ++j) {
						Word t = adj[p][i][j];
						int cost = t.size;
						int u = t.id;
						if(D[v]+cost < D[u]) {
							D[u] = D[v]+cost;
							Q.push(Node(u,D[u],t.ch,t.lang1,t.lang2));
						}
					}
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
		id_lang.clear();
		for(int i = 0; i <= N*2+1; ++i)
			for(int j = 0; j < 26; ++j)
				adj[i][j].clear();
		getline(cin,buf); 
		istringstream ncin(buf);
		getline(ncin,O,' ');
		getline(ncin,T,' ');
		int M=0;
		for(int i=0; i < N; ++i) {
			getline(cin,buf);
			istringstream ncin2(buf);
			getline(ncin2,L1,' ');
			getline(ncin2,L2,' ');
			getline(ncin2,P,' ');
			if(id_lang.count(L1)==0)id_lang[L1] = M++;
			if(id_lang.count(L2)==0)id_lang[L2] = M++;
			Word w(i,P[0],P.size(),id_lang[L1],id_lang[L2]);
			adj[id_lang[L1]][P[0]-'a'].push_back(w);
			adj[id_lang[L2]][P[0]-'a'].push_back(w);
		}
		if(id_lang.count(O)==0 || id_lang.count(T)==0) {
			puts("impossivel");
		} else {
			isrc=id_lang[O];
			idst=id_lang[T];
			ans=dijkstra();
			if(ans>=0)printf("%d\n",ans);
			else puts("impossivel");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

