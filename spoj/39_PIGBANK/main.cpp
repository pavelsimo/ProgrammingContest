#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int INF = 99999999;
int n;
int ans;
int V[600];
int W[600];
int dp[20000];

int d(int S) {
   dp[0] = 0;
   for(int i = 1; i <= S; ++i)
      dp[i]=INF; 
   for(int i = 0; i < n; ++i) {
      for(int j = 1; j <= S; ++j) {
         if(j >= W[i]) {
            dp[j] = min(dp[j],dp[j-W[i]]+V[i]);
         }
      }
   }
   return dp[S];
}

int main(int argc, char *argv[]) {
	int TC, E, F, value, weight;
	scanf("%d",&TC);
	while(TC-- > 0) {
		ans = INF;
		scanf("%d%d%d",&E,&F,&n);
		for(int i = 0 ; i < n; ++i) {
			scanf("%d%d",&value,&weight);
			W[i]=weight;
			V[i]=value;
		}
		ans = d(F-E);
		if(ans==INF) printf("This is impossible.\n");
      else printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
	}
	return 0;
}
