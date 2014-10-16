/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10341  C++  "Binary Search" */
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

const double eps = 1e-5;
const double e = 2.71828182845904523536;

int main(int argc, char *argv[]) {
	int p, q, r, s, t, u;
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6) {
		double lo = 0.0;
		double hi = 1.0;
		double x, ans;
		for(int i = 0; i < 100; ++i) {
			x = lo + (hi-lo)/2.0;
			ans = p*pow(e,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
			if(ans > 0)
				lo = x;
			else
				hi = x;
		}
		if(fabs(ans) > eps) puts("No solution");
		else printf("%.4lf\n",x);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

