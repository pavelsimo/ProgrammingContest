#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
using namespace std;

const int maxn = 38;

int a[maxn];
int b[maxn];

int doit(int n) {
	for(int j = n; j >= 1; --j) {
		int cnt = 0;
		int i = 2*j-1;
		
	
	}
	
	


}


int main(int argc, char *argv[]) {
	int TC,n,k,x;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&k);
		for(int i = 0; i < k; ++i) {
			scanf("%d",&x);
			a[x]=1;
		}
		
	}


	return 0;
}
