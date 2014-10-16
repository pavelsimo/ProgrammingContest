#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1010;
int v[maxn], a[maxn], b[maxn];

int memo[maxn][maxn];

int d(int i, int j) {
	


}


int main(int argc, char *argv[]) {

	int TC,C,oxygen,nitrogen,n,;
	scanf("%d",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));
		scanf("%d%d%d",&oxygen,&nitrogen,&n);
		C = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d%d%d",a+i,b+i,v+i);
			C +=v[i];
		}
		printf("%d\n",d(0,C));
	}
	return 0;
}
