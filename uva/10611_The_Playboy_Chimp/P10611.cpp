/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10611  C++  "Binary Search" */
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
const int maxn = 50010;
VI a;

int main(int argc, char *argv[]) {
	int N, Q, x;
	scanf("%d",&N);
	for(int i = 0; i < N; ++i) {
		scanf("%d",&x);
		a.push_back(x);
	}
	scanf("%d",&Q);
	for(int i = 0; i < Q; ++i) {
		scanf("%d",&x);
		int lower = int(lower_bound(a.begin(),a.end(),x) - a.begin());
		int upper = int(upper_bound(a.begin(),a.end(),x) - a.begin());
		if(lower-1 >= 0) printf("%d ",a[lower-1]);
		else printf("X ");
		if(upper < N) printf("%d",a[upper]);
		else printf("X");
		putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

