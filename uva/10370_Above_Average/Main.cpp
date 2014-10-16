/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10370  C++  "Simple Algorithm" */
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
typedef vector<int> VI;
typedef vector<string> VS;

template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int m, k, sum=0;     
        cin >> m;
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            cin >> k;  
            sum += k;
            v.push_back(k);
        }
        double avg = (double)(sum/m);
        int cnt = 0;
        for(int j = 0; j < m; ++j)
            if ( v[j] > avg )
                cnt++;
        float res = (float)(100*cnt)/m; 
        printf("%0.3f%\n", res);    
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
