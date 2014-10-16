/*
ID: 0000
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxn = 210;
bool a[maxn];
priority_queue<int,vector<int>,greater<int> > Q;

int main() {
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
	int M, S, C, k, ans=0, c=0, b=0;
	memset(a,false,sizeof(a));
	scanf("%d%d%d",&M,&S,&C);
	int ub = 0, lb = 201;
	for(int i = 0; i < C; ++i) {
		scanf("%d",&k);
		a[k]=true;
		ub = max(ub,k);
		lb = min(lb,k);
	}
	for(int i = lb; i <= ub; ++i) {
		if(a[i]) {
			ans++; c=0;
		} else {
			c++;
		}
		if(!a[i] && a[i+1]) Q.push(c);
		if(a[i] && !a[i+1]) b++;
	}
	while(b > M && !Q.empty()) {
		int cur = Q.top(); Q.pop();
		ans+=cur;
		b--;
	}
	printf("%d\n",ans);
	return 0;
}
