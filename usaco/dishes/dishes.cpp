/*
ID: 12
PROG: dishes
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

#define WASH 1
#define DRY 2

int N, cmd, k;
stack<int> A, B, C;

int main() {
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	scanf("%d",&N);
	for(int i = N; i >= 1; --i) 
		A.push(i);
	while(scanf("%d%d",&cmd,&k)==2) {
		if(cmd==WASH) {
			while(k-- > 0) {
				if(!A.empty()) {
					int cur = A.top(); A.pop();
					B.push(cur);
				}
			}
		} else if(cmd==DRY) {
			while(k-- > 0) {
				if(!B.empty()) {
					int cur = B.top(); B.pop();
					C.push(cur);
				}
			}
		}
	}
	while(!C.empty()) {
		printf("%d\n",C.top());
		C.pop();
	}
	return 0;
}
