/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  222  C++  "String Manipulation" */
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

struct Station {
	double dist;
	double price;
};

double INF = 1000000000000.0;
int N;
Station station[60];
double dst, gallon_capacity, miles_per_gallon, fill_price_src, 
	distance, price_per_gallon, half_tank, max_dist;

double doit(int cur, double fuel) {
	if(fuel <= 0) return INF;
	if(cur==N+1) return 0.0;
	int nxt = cur+1;
	double dx = station[nxt].dist - station[cur].dist;
	double consume = (dx/miles_per_gallon);
	double ans = INF;
	ans = min(ans,doit(nxt,fuel-consume)); // not fill the tank
	if(fuel*2.0 < gallon_capacity || consume > fuel) { 
      // fill the tank
		ans = min(ans,doit(nxt,gallon_capacity-consume) + (station[cur].price*(gallon_capacity-fuel))/100.0 + 2.0);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int tc=1;
	while(scanf("%lf",&dst)==1) {
		if(dst<0) break;
		scanf("%lf%lf%lf%d",&gallon_capacity,&miles_per_gallon,&fill_price_src,&N);
		station[0].dist = 0;
		station[N+1].dist = dst;
		for(int i = 1; i <= N; ++i) {
			scanf("%lf%lf",&station[i].dist,&station[i].price);
		}
		printf("Data Set #%d\n",tc++);
		printf("minimum cost = $%.2f\n",doit(0,gallon_capacity)+fill_price_src);
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

