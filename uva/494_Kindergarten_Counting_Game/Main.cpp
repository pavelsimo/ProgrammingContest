/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 494  C++  "Ad Hoc" */
#include <algorithm>
#include <numeric>
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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
    string s;
    while( getline(cin,s) != NULL) {
        int res = 0;
        s = s + " ";
        for(int i = 0; i < s.length()-1; ++i) {
            if ( isalpha(s[i]) && !isalpha(s[i+1]) )
                res++;
        }
        printf("%d\n",res);
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
