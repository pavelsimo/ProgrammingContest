/*
ID: 13
PROG: hexagon
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
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
using namespace std;

set<int> SS;

void doit(int cur, int dist, int K, int L) {
	int a[6];
	int N = (K*3)*(K-1)+1;
	for(int i = 0; i < 6; ++i) a[i] = cur;
	for(int i = 0; i < L; ++i) {
		a[0]+=1;
		a[1]-=1;
		a[2]+=K+1;
		a[3]-=K+1;
		a[4]+=K+2;
		a[5]-=K+2;	
	}
	for(int i = 0; i < 6; ++i)  {
		if(a[i] >= 1 && a[i] <= N) {
			SS.insert(a[i]);
		}
	}
}


int main() {
	//freopen("hexagon.in", "r", stdin);
	//freopen("hexagon.out", "w", stdout);
	int K, H, L;
	scanf("%d%d%d",&K,&H,&L);
	
	
	doit(H,0,K,L);
	FORE(SS,it) {
		cout << *it << endl;
	}
	
	/*
	int cnt = 0;
	int i, j;
	
	for(i=0, j=0; i < 2*K-1; ++i) {
		cnt += K+j;
		if(cnt >= H) break;
		if(i < K-1) j++;
		else j--;
	}
	if(i-1 >= 0) {
		int sum = cnt-(K+j);
		for(int p = sum; p > sum-(K+j-1); --p)
			cout << p << endl;
	}
	if(i+1 < 2*K-1) {
		int r = j;
		if(i+1 < K-1) r++;
		else r--;
		int sum = cnt+(K+r);
		for(int p = sum; p > sum-(K+r); --p)
			cout << p << endl;
	}
	*/
	return 0;
}
