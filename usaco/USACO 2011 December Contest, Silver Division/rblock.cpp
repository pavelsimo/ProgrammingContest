/*
ID: 2
PROG: rblock
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)


typedef long long llong;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int MAXN = 110;
const int INF = 0x3f3f3f3f;
vii adj[MAXN];
vector<int> A;
int D[MAXN], P[MAXN], C[MAXN][MAXN], n, m;

int dijkstra(int src, int dst) {
   memset(D,0x3f,sizeof(D));
   memset(P,-1,sizeof(P));
   priority_queue<ii,vector<ii>,greater<ii> > Q;
   Q.push(ii(0,src));
   D[src]=0;
   while(!Q.empty()) {
      ii cur = Q.top(); Q.pop();
      int d = cur.first;
      int v = cur.second;
      if(v==dst) return d;
      if(d <= D[v]) {
         for(int i = 0; i < sz(adj[v]); ++i) {
            ii nxt = adj[v][i];
            int cost = nxt.first;
            int u = nxt.second;
            if(D[v]+cost < D[u]) {
               P[u] = v;
               D[u] = D[v]+cost;
               Q.push(ii(D[u],u));
            }
         }
      }
   }
   return -1;
}

int main(int argc, char *argv[]) {
   int src, dst, v, u, d, ans;
   //freopen("rblock.in", "r", stdin);
   //freopen("rblock.out", "w", stdout);
   scanf("%d%d",&n,&m);
   src = 1;
   dst = n;
   A.clear();
   memset(C,0,sizeof(C));
   for(int i = 0; i <= n; ++i) 
      adj[i].clear();
   for(int i = 0; i < m; ++i) {
      scanf("%d%d%d",&v,&u,&d);
      adj[v].push_back(ii(d,u));
      adj[u].push_back(ii(d,v));
      C[v][u] = d;
      C[u][v] = d;
   }
   ans=dijkstra(src,dst);
   int hi = 0, lo = INF;
   for(int i=n; i!=1; i=P[i])
      hi = max(hi, ans-C[i][P[i]]+(C[i][P[i]]*2));
   DEBUG(lo);
   DEBUG(hi);
   printf("%d\n",max(0,min(hi,lo)-ans));
   return 0;
}


