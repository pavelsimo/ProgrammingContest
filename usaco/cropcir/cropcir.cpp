/*
ID: 14
PROG: cropcir
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

int x[410];
int y[410];
int R[410];

int dist(int x1, int y1, int x2,  int y2) {
	int dx = x1-x2;
	int dy = y1-y2;
	return dx*dx+dy*dy;
}

int main() {
	freopen("cropcir.in", "r", stdin);
	freopen("cropcir.out", "w", stdout);
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; ++i) {
		scanf("%d%d%d",&x[i],&y[i],&R[i]);
	}
	for(int i = 0; i < N; ++i) {
		int cnt = 0;
		for(int j = 0; j < N; ++j) {
			if(i==j) continue;
			int d = R[i]+R[j];
			if(dist(x[i],y[i],x[j],y[j]) <= d*d) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
