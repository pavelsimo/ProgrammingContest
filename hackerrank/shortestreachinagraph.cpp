/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1002;
int dis[MAXN];
int seen[MAXN];

void bfs(int src, vector<vector<int> > &edges) {
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    seen[src] = 1;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();        
        for(int i = 0; i < edges[cur].size(); ++i) {
            int nxt = edges[cur][i];
            if(dis[nxt] == -1) {
                dis[nxt] = dis[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    int queries;
    cin >> queries;    
    for (int t = 0; t < queries; t++) {
        for(int i = 0; i < MAXN; ++i) {
            dis[i] = -1;
        }
        
        int n, m;
        cin >> n;        
        cin >> m;
        vector<vector<int> > edges(n);        
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges[u].push_back(v);
            edges[v].push_back(u);            
        }
        
        int src;
        cin >> src;
        src--;
       
        bfs(src, edges);
        for (int i = 0; i < n; i++) {
            if (i != src) {
                cout << (dis[i] == -1 ? -1 : dis[i] * 6) << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
