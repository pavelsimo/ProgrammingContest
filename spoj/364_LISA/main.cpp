#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
const LL INF = 1000000000000000000LL;
const int maxn = 200;
int n;
string s;
LL memo1[maxn][maxn];
LL memo2[maxn][maxn];

LL dmax(int cur=0, int end=s.size()) {
	LL ans = 0LL;
	if(cur+1==end) return LL(s[cur]-'0');
	if(memo1[cur][end] >= 0LL) return memo1[cur][end];
	for(int i=cur; i < end; ++i) {
		if(s[i]=='*') ans=max(ans,dmax(cur,i)*dmax(i+1,end));
		if(s[i]=='+') ans=max(ans,dmax(cur,i)+dmax(i+1,end));
	}
	return memo1[cur][end]=ans;
}

LL dmin(int cur=0, int end=s.size()) {
	LL ans = INF;
	if(cur+1==end) return LL(s[cur]-'0');
	if(memo2[cur][end] >= 0LL) return memo2[cur][end];
	for(int i=cur; i < end; ++i) {
		if(s[i]=='*') ans=min(ans,dmin(cur,i)*dmin(i+1,end));
		if(s[i]=='+') ans=min(ans,dmin(cur,i)+dmin(i+1,end));
	}
	return memo2[cur][end]=ans;
}

int main(int argc, char *argv[]) {
	int TC;
	cin >> TC;
	while(TC--) {
		memset(memo1,-1,sizeof(memo1));
		memset(memo2,-1,sizeof(memo2));
      cin >> s;
		printf("%lld %lld\n",dmax(),dmin());
	}
	return 0;
}
