/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10651  C++  "DP bitmask" */
#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
using namespace std;

const int INF = 12;
const int n = 12;
char buf[32];
int memo[1<<13];

bool bset(int mask, int bit) {
	return (mask&(1<<bit))!=0;
}

int move(int mask, int A, int B, int C) {
	int ans=mask;
	ans|=(1<<A);
	ans &=~(1<<B);
	ans &=~(1<<C);
	return ans;
}

int d(int board) {
	int ans = INF;
	if(memo[board] >= 0) return memo[board];
	ans = min(ans,BITCOUNT(board));
	for(int i = 0; i < n; ++i) {	
		if(i-1>=0 && i-2>=0) {
			if(!bset(board,i)&&bset(board,i-1)&&bset(board,i-2)) {
				int ns = move(board,i,i-1,i-2);
				ans = min(ans,d(ns));
			}		
		}
		if(i+1<n && i+2<n) {
			if(!bset(board,i)&&bset(board,i+1)&&bset(board,i+2)) {
				int ns = move(board,i,i+1,i+2);
				ans = min(ans,d(ns));
			}			
		}
	}
	return memo[board] = ans;
}

int main(int argc, char *argv[]) {
	int TC, board, ans;
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		memset(memo,-1,sizeof(memo));
		gets(buf);
		board=0;
		for(int i = 0; i < n; ++i)
			if(buf[i]=='o') board|=(1<<i);
		ans = d(board);
		printf("%d\n",ans);
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

