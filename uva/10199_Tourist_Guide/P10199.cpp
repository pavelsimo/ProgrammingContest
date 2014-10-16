/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10199  C++  "DFS Flood Fill" */
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
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
using namespace std;

typedef vector<string> VS;
typedef vector<int> VI;

int N, M;
const int maxn = 102;
map<string,int> m_id;
int num[maxn], low[maxn], P[maxn];
bool AP[maxn];
int root, root_child, id;
VI adj[maxn];
VS a, out;

// Articulation Points
void dfs(int cur) {
	num[cur]=low[cur]=++id;
	for(int i = 0; i < adj[cur].size(); ++i) {
		int nxt = adj[cur][i];
		if(!num[nxt]) {
			P[nxt] = cur;
			if(cur==root) 
				root_child++;
			dfs(nxt);
			if(low[nxt] >= num[cur]) 
				AP[cur] = true;
			low[cur] = min(low[cur],low[nxt]);
		} else {
			if(P[cur]!=nxt)
				low[cur] = min(low[cur],num[nxt]);
		}
	}
}

int main() {
	int TC = 0;
	string buf, u, v;
	int isrc, idst, ans;
	while(getline(cin,buf)) {
		if(1!=sscanf(buf.c_str(),"%d",&N) || N==0) break;
		
		if(TC > 0) putchar('\n');
		
		m_id.clear();
		a.clear();
		out.clear();
		memset(num,0,sizeof(num));
		memset(low,0,sizeof(low));
		memset(P,0,sizeof(P));
		memset(AP,false,sizeof(AP));
		
		for(int i = 0; i <= N; ++i) adj[i].clear();
		
		for(int i = 0; i < N; ++i) {
			getline(cin,buf);
			m_id[buf] = i;
			a.push_back(buf);
		}
		getline(cin,buf);
		sscanf(buf.c_str(),"%d",&M);
		for(int i = 0; i < M; ++i) {
			getline(cin,buf);
			istringstream in(buf);
			in >> u >> v;
			isrc = m_id[u];
			idst = m_id[v];
			adj[isrc].push_back(idst);
			adj[idst].push_back(isrc);
		}
		for(int i = 0; i < N; ++i) {
			if(!num[i]) {
				root = i;
				root_child = 0;
				dfs(root);
				AP[root] = (root_child>1);			
			}
		}
		ans=0;
		for(int i = 0; i < N; ++i) {
			if(AP[i]) {
				out.push_back(a[i]);
				ans++;
			}
		}
		sort(out.begin(),out.end());
		printf("City map #%d: %d camera(s) found\n",++TC,ans);
		for(int i = 0; i < out.size(); ++i)
			printf("%s\n",out[i].c_str());
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
