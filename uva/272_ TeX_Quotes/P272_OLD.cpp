/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  272 10783  C++  "Ad Hoc" */
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
    string str;
    string pattern = "\"";
    string replace1 = "``";
    string replace2 = "''";
    string rpl = replace1;
    int quotes = 0;
    while(getline(cin,str)!=NULL) {
        string::size_type pos = 0;
        while ( (pos = str.find(pattern, pos)) != string::npos ) {
            str.replace( pos, pattern.size(), rpl );
            pos++;
            quotes++;
            if (quotes%2 == 0) 
                rpl = replace1;
            else 
                rpl = replace2;
        }
        cout << str << endl;
    }
	return 0;
}
/* @END_OF_SOURCE_CODE */
