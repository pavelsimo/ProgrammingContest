/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  489  C++  "Ad Hoc" */
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

int feq[256];

int main(int argc, char *argv[]) {
	int N, life, score, lose;
	string solution, guesses;
	while(scanf("%d\n",&N)==1) {
		if(N==-1)break;
		memset(feq,0,sizeof(feq));
		getline(cin,solution);
		getline(cin,guesses);
		score=0;
		lose = 0;
		life = 7;
		REP(i,solution.size()) {
			feq[solution[i]]++;
			score++;
		}
		REP(i,guesses.size()) {
			if(feq[guesses[i]] > 0) {
				score-=feq[guesses[i]];
				feq[guesses[i]]=0;
				if(score <= 0) break;
			} else 
				life--;
			if(life <= 0) {
				lose = 1;
				break;
			}
		}
		if(lose)
			printf("Round %d\nYou lose.\n",N);
		else if(score <= 0)
			printf("Round %d\nYou win.\n",N);
		else
			printf("Round %d\nYou chickened out.\n",N);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

