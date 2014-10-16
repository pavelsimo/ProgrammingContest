/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10662  C++  "Brute Force" */
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

int INF = 1000000000;
int travel_agencies[22][22];
int restaurants[22][22];
int hotels[22][22];

int main(int argc, char *argv[]) {
	int T, R, H, price, u, ans[3], best;
	while(scanf("%d%d%d",&T,&R,&H)==3) {
		for(int i = 0; i < T; ++i) {
			scanf("%d",&price);
			for(int j = 0; j < R; ++j) {
				scanf("%d",&u);
				if(!u) travel_agencies[i][j] = price;
				else travel_agencies[i][j] = -INF;
			}
		}
		for(int i = 0; i < R; ++i) {
			scanf("%d",&price);
			for(int j = 0; j < H; ++j) {
				scanf("%d",&u);
				if(!u) restaurants[i][j] = price;
				else restaurants[i][j] = -INF;
			}
		}
		for(int i = 0; i < H ; ++i) {
			scanf("%d",&price);
			for(int j = 0; j < T; ++j) {
				scanf("%d",&u);
				if(!u) hotels[i][j] = price;
				else hotels[i][j] = -INF;
			}
		}
		best = INF;
		for(int t = 0; t < T; ++t) {
			for(int r = 0; r < R; ++r) {
				for(int h = 0; h < H; ++h) {
					if(travel_agencies[t][r] >= 0 && restaurants[r][h] >= 0 && hotels[h][t] >= 0) { 
						int offer_price = travel_agencies[t][r]+restaurants[r][h]+hotels[h][t];
						if(offer_price < best) {
							ans[0] = t; ans[1] = r; ans[2] = h;
							best = offer_price;
						}
					}
				}
			}
		}
		if(best!=INF) printf("%d %d %d:%d\n",ans[0],ans[1],ans[2],best); 
		else puts("Don't get married!");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

