/*
ID: 13
PROG: commas
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

char buf[255];

int main() {
	freopen("commas.in", "r", stdin);
	freopen("commas.out", "w", stdout);
	int n;
	string ans="";
	gets(buf);
	n = strlen(buf);
	for(int i = n-1,j=0; i >=0; --i) {
		if(j%3==0 && j!=0) ans=','+ans;
		ans=buf[i]+ans;
		j++;
	}
	printf("%s\n",ans.c_str());
   return 0;
}
