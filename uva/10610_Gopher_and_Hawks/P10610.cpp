/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10610  C++  "Graph Theory, BFS" */
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

const int INF=-1;
const double eps = 1e-9;
const int maxn = 1024;
typedef pair<double,double> dd;
typedef vector<dd> vdd;
char buf[maxn];
vdd P;
vector<int> adj[maxn];
int D[maxn];

double dist(double x1, double y1, double x2,  double y2) {
	double dx = x1-x2;
	double dy = y1-y2;
	return dx*dx+dy*dy;
}

double LessOrEqual(double a, double b) {
	if(fabs(a-b) < eps) return true;
	return a < b;
}

int bfs(int src, int dst) {
	memset(D,INF,sizeof(D));
	queue<int> Q;
	Q.push(src);
	D[src]=0;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if(cur==dst) return D[cur];
		for(int i = 0; i < adj[cur].size(); ++i) {
			int nxt = adj[cur][i];
			if(D[nxt]==INF) {
				D[nxt] = D[cur] + 1;
				Q.push(nxt);
			}		
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	double sx,sy,tx,ty,hx,hy;
	int v, m, ans;
	while(gets(buf)) {
		P.clear();
		for(int i = 0; i < maxn; ++i) adj[i].clear(); 
		sscanf(buf,"%d%d",&v,&m);
		if(v==0&&m==0) break;
		gets(buf);
		sscanf(buf,"%lf%lf",&sx,&sy);
		gets(buf);
		sscanf(buf,"%lf%lf",&tx,&ty);
		P.push_back(dd(sx,sy));
		P.push_back(dd(tx,ty));
		while(gets(buf)) {
			if(sscanf(buf,"%lf%lf",&hx,&hy)!=2) break;
			P.push_back(dd(hx,hy));
		}
		double c=(m*60.0)*v;
		c*=c;
		for(int i = 0; i < P.size()-1; ++i) {
			for(int j = i+1; j < P.size(); ++j) {
				double d = dist(P[i].first,P[i].second,P[j].first,P[j].second);
				if(LessOrEqual(d,c)) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		ans=bfs(0,1);
		if(ans>=0) printf("Yes, visiting %d other holes.\n",ans>0?ans-1:ans);
		else puts("No.");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

