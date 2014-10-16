/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10496  C++  "Brute Force" */
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

struct Point {
	int x;
	int y;
};

const int INF = 100000000;
int id[20];
Point p[20];

int main(int argc, char *argv[]) {
	int TC, nrow, ncol, sx,sy,n, ans, cost;
	scanf("%d",&TC);
	while(TC-- > 0) {
		scanf("%d%d%d%d%d",&nrow,&ncol,&sx,&sy,&n);
		for(int i = 0; i < n; ++i) {
			id[i] = i;
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		ans=INF;
		do {
			cost=0;
			cost+=abs(sx-p[id[0]].x)+abs(sy-p[id[0]].y);
			cost+=abs(sx-p[id[n-1]].x)+abs(sy-p[id[n-1]].y);
			for(int i = 0; i < n-1; ++i)
				cost+=abs(p[id[i]].x-p[id[i+1]].x)+abs(p[id[i]].y-p[id[i+1]].y);
			ans = min(ans,cost);
		} while(next_permutation(id,id+n));
		printf("The shortest path has length %d\n",ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

