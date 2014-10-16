/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  957  C++  "Binary Search" */
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

typedef vector<int> VI;
VI a;

int main(int argc, char *argv[]) {
	int N, Y, x, best, src, dst;
	while(scanf("%d%d",&Y,&N)==2) {
		a.clear();
		for(int i = 0; i < N; ++i) {
			scanf("%d",&x);
			a.push_back(x);
		}
		best=src=dst=0;
		for(int i = 0; i < N; ++i) {
			int j = int(lower_bound(a.begin(),a.end(),a[i]+Y) - a.begin());
			if(j-i > best) {
				src = i;
				dst = max(0,j-1);
				best = j-i;
			}
		}
		printf("%d %d %d\n",best,a[src],a[dst]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

