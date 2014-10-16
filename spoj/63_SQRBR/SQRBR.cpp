#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
using namespace std;

typedef long long LL;
const int maxn = 40;
int a[maxn][maxn];
int b[maxn];

int doit(int n) {
	memset(a,0,sizeof(a));
	a[0][n+1] = 1;
	for(int i = n; i >= 1; --i) {
		if(b[2*i]) {
			a[0][i] += a[1][i+1];  
		} else {
			a[0][i] += a[0][i+1];
			a[0][i] += a[1][i+1];
		}
		for(int j = 1; j < i; ++j) {		
			if(b[2*i-1] && b[2*i]) {	//[[
				a[j][i] += a[j+1][i+1]; // [[
			} else if(!b[2*i-1] && !b[2*i]) {	//**
				a[j][i] += a[j+1][i+1];  // [[
				a[j][i] += 2*a[j][i+1];  // [] ][
				a[j][i] += a[j-1][i+1];  // ]]
			// lo mismo que else lo dejamos para que se entendiera mejor
			} else if(!b[2*i-1] && b[2*i]) {	//*[ 
				a[j][i] += a[j+1][i+1];  // [[
				a[j][i] += a[j][i+1];    // ][ 
			} else {		//[*
				a[j][i] += a[j+1][i+1];  // [[
				a[j][i] += a[j][i+1];    // []
			}
		}
	}
	return a[0][1];
}

int main(int argc, char *argv[]) {
	int TC, n, k, idx;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&k);
		for(int i = 0; i < k; ++i) {
			scanf("%d",&idx);
			b[idx]=1;
		}
		printf("%d\n",doit(n));
	}
	return 0;
}
