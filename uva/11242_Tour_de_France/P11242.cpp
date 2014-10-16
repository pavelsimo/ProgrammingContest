/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11242  C++  "Ad Hoc" */
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
using namespace std;

const double eps = 1e-5;
int front[12], rear[12];
double a[110];

double LessOrEqual(const double &a, const double &b) {
	if(fabs(a-b) < eps) return true;
	return a < b;
}

struct cmp {
	bool operator()(const double &a, const double &b) {
		return LessOrEqual(a,b);
	}
};

int main(int argc, char *argv[]) {
	int F, R, N, cur;
	double ans;
	while(scanf("%d%d",&F,&R)==2) {
		for(int i = 0; i < F; ++i)
			scanf("%d",&front[i]);
		for(int i = 0; i < R; ++i)
			scanf("%d",&rear[i]);
		N = F*R;
		for(int i = 0; i < F; ++i) {
			for(int j = 0; j < R; ++j)
				a[i*R+j] = 1.0*front[i]/rear[j];
		}
		sort(a,a+N,cmp());
		ans=0.0;
		for(int i = 0; i < N-1; ++i) {
			double d = a[i+1]/a[i];
			if(!LessOrEqual(d,ans)) ans = d;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
