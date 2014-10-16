/*
ID: 0000
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

struct Farmer {
	int start;
	int end;
	bool operator<(const Farmer &T) const {
		if(T.start!=start) return start < T.start;
		return false;
	}
};

const int maxn = 5010;
Farmer a[maxn];

int main() {
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
		scanf("%d%d",&a[i].start,&a[i].end);
	sort(a,a+N);
	int s=a[0].start, e=a[0].end, maxi=0, maxj=0;
	for(int i = 0; i < N; ++i) {
		if(a[i].start > e) {
			if(a[i].start-e > maxj) maxj=a[i].start-e;
			s = a[i].start; e = a[i].end;
		} else {
			if(a[i].end > e) e = a[i].end;
			if(e-s > maxi) maxi = e-s;
		}	
	}
	printf("%d %d\n",maxi,maxj);
	return 0;
}
