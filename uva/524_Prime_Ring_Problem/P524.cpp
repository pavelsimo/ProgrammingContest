/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  524  C++  "Backtracking, Primes" */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 32;
int vis[MAXN];
int C[MAXN];
int prime[MAXN+2];

void sieve(int n) {
   for(int i = 0; i <= n; ++i) prime[i] = 1;
   prime[0]=0;
   prime[1]=0;
   int m = (int)sqrt(n);
   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=0;
} 

void search(int cur, int n) {
	if(cur == n) {
		if(prime[C[0]+C[cur-1]]) {
			for(int i = 0; i < n; ++i) {
				if(i!=0) printf(" ");
				printf("%d",C[i]);
			}
			putchar('\n');		
		}
		return;
	}
	for(int i = 2; i <= n; ++i) {
		if(!vis[i]) {
			int ok = 1;
			C[cur] = i;
			if(!prime[C[cur-1]+C[cur]]) ok = 0;
			if(ok) {
				vis[i] = 1;
				search(cur+1,n);
				vis[i] = 0;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n, TC=0; 
	sieve(MAXN+1);	
	while(scanf("%d",&n)==1) {
		if(TC!=0) putchar('\n');
		memset(C,0,sizeof(C));
		memset(vis,0,sizeof(vis));
		C[0] = 1;
		printf("Case %d:\n",++TC);
		search(1,n);
	}	
	return 0;
}
/* @END_OF_SOURCE_CODE */
