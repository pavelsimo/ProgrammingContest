/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10018  C++  "Ad Hoc" */
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

unsigned long rev(unsigned long x) {
    string s = tostr(x);
    reverse(s.begin(),s.end());
    return atol(s.c_str());
}

unsigned long isPal(unsigned long x) {
    string s1 = tostr(x);
    string s2 = tostr(x);
    reverse(s1.begin(),s1.end());
    return s1==s2;
}

int main() {
    int n;
    unsigned long x;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        scanf("%lu",&x);        
        while(true) {
            x += rev(x);
            cnt++;
            if(isPal(x)) break;
        }
        printf("%d %lu\n",cnt,x);
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
