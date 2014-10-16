/*
ID: 11
PROG: bookclub
LANG: C++
*/
#include <cstring>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define DEBUG
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

short t[50010];
vector<int> memo[55][10];

int main() {
	freopen("bookclub.in", "r", stdin);
	freopen("bookclub.out", "w", stdout);
	int N, NQ, P, question, answer, res, ans;
	memset(t,0,sizeof(t));
	scanf("%d%d%d",&N,&NQ,&P);
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= NQ; ++j) {
			scanf("%d",&ans);
			memo[j][ans].push_back(i);
		}
	}
	for(int i = 1; i <= P; ++i) {
		scanf("%d%d",&question,&answer);
		for(int j = 0; j < memo[question][answer].size(); ++j) {
			t[memo[question][answer][j]]++;
		}
	}
	res=0;
	for(int i = 1; i <= N; ++i) 
		if(t[i]==P) res++;
	printf("%d\n",res);
   return 0;
}
