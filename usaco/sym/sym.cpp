/*
ID: 11
PROG: sym
LANG: C++
*/
#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
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

typedef long long llong;

int main() {
	freopen("sym.in", "r", stdin);
	freopen("sym.out", "w", stdout);
	llong N, M, ans=0, k=1;
	scanf("%lld%lld",&N,&M);
	while(N>0 && M>0) {
		if(N%2==0||M%2==0) break;
		ans+=k;
		N/=2;
		M/=2;
		k*=4;
	}
	printf("%lld\n",ans);
	return 0;
}
