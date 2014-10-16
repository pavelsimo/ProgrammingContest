/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11516  C++  "Binary Search" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int N, M;
const int maxn = 100010;
int a[maxn];

bool check(double d) {
	int used = 1;
	double signal = a[0] + d;
	for(int i = 0; i < M; ++i) {
		if(a[i] > signal && fabs(a[i]-signal) > d) {
			signal = a[i] + d;
			used++;
		}
	}
	return used<=N;
}

int main(int argc, char *argv[]) {
	int TC;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d",&N,&M);
		double lo = 0.0;
		double hi = 1000000.0;
		for(int i = 0; i < M; ++i)
			scanf("%d",&a[i]);
		if(N >= M) {
			puts("0.0");
		} else {
			sort(a,a+M);
			for(int i = 0; i < 100; ++i) {
				double mid = lo + (hi-lo)/2.0;
				if(check(mid)) 
					hi = mid;
				else 
					lo = mid;
			}
			printf("%.1lf\n",lo);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

