/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11262  C++  "Binary Search" */
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
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;

struct Point {
	int index;
	int x;
	int y;
	int color;
};

int dist(Point a, Point b) {
	int dx = a.x-b.x;
	int dy = a.y-b.y;
	return dx*dx+dy*dy;
}

struct PairPoint {
	Point a;
	Point b;
	PairPoint(Point _a, Point _b) {
		a = _a;
		b = _b;
	}
	bool operator<(const PairPoint &T) const {
		return dist(T.a,T.b) < dist(a,b);
	}
};

int N, K;
const int maxn = 102;
const int BLUE = 1, RED = 0;
Point p[maxn];
int D[maxn][maxn];
bool vis[maxn];
char buf[256], temp[64];

bool check(int d) {
	// DEBUG
	// printf("begin check() d=%d\n",d);
	memset(vis,false,sizeof(vis));
	int used = 0;
	priority_queue<PairPoint> Q;
	for(int i = 0; i < N; ++i) {
		for(int j = i+1; j < N; ++j) {
			if(p[i].color==p[j].color) continue;
			int cur = dist(p[i],p[j]);
			if(cur <= d*d) 
				Q.push(PairPoint(p[i],p[j]));
		}
	}
	while(!Q.empty()) {
		PairPoint cur = Q.top();
		Q.pop();
		Point p1 = cur.a;
		Point p2 = cur.b;
		// DEBUG
		// printf("(%d,%d) (%d,%d) d=%d\n",p1.x,p1.y,p2.x,p2.y,dist(p1,p2));
		if(vis[p1.index] || vis[p2.index]) continue;
		vis[p1.index] = true;
		vis[p2.index] = true;
		used++;
	}
	// DEBUG
	// printf("end check() used=%d\n",used);
	return used>=K;
}

int binary_search() {
	int lo = 0;
	int hi = 10000;
	int mid;
	while(lo < hi) {
		mid = lo + (hi-lo)/2;
		// DEBUG
		// printf("lo=%d mid=%d hi=%d\n",lo,mid,hi);
		if(check(mid))
			hi = mid;
		else
			lo = mid+1;
	}
	return lo;
}

int main() {
	int TC, ans;
	gets(buf);
	sscanf(buf,"%d",&TC);
	while(TC-- > 0) {
		gets(buf);
		gets(buf);
		sscanf(buf,"%d%d",&N,&K);
		for(int i = 0; i < N; ++i) {
			gets(buf);
			sscanf(buf,"%d %d %s",&p[i].x,&p[i].y,temp);
			p[i].index = i;
			p[i].color=(temp[0]=='b')?BLUE:RED;
		}
		// DEBUG
		// for(int i = 0; i < N; ++i) {
		// 	 printf("%d %d\n",p[i].x,p[i].y);
		// }
		ans = binary_search();
		if(check(ans)) printf("%d\n",ans);
		else puts("Impossible");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
