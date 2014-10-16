/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  102  C++  "Ad Hoc, Greedy" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define N 6
#define INF 2147483647

int DP[255];
int B[3]; // brown
int G[3]; // green 
int C[3]; // clear
char pack[N][4] = {"BCG","BGC","CBG","CGB","GBC","GCB"};

int score(int A[3], char ch, int pos) {
	switch(pos) {
		case 0:
			DP[ch] = A[1]+A[2];
		break;
		case 1:
			DP[ch] = A[0]+A[2];
		break;
		case 2:
			DP[ch] = A[0]+A[1];
		break;
	}
}

int main(int argc, char *argv[]) {
	while ( scanf("%d %d %d %d %d %d %d %d %d",
				&B[0],&G[0],&C[0],
				&B[1],&G[1],&C[1],
				&B[2],&G[2],&C[2]) == 9) {
		int ans = INF;
		int index = 0;
		for(int i = 0; i < N; ++i) {
			memset(DP,0,sizeof(DP));
			for(int j = 0; j < 3; ++j) {
				if ( pack[i][j] == 'B') score(B,'B',j);
				if ( pack[i][j] == 'G') score(G,'G',j);
				if ( pack[i][j] == 'C') score(C,'C',j);
			}
			if (DP['B']+DP['G']+DP['C'] < ans) {
				ans = DP['B']+DP['G']+DP['C'];
				index = i;
			}
		}
		printf("%s %d\n",pack[index],ans);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

