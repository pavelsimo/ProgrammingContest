/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  4217 10062  C++  "Ad Hoc" */
#include <cstring>
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

#define N 270
int f[N];

struct node {
    int key;
    int value;
    node(int nkey, int nvalue) {
        key = nkey;
        value = nvalue;
    }
};

bool operator<(const node &a, const node &b) {
  if ( a.value != b.value ) 
    return b.value > a.value;
  if ( a.key != b.key ) 
    return b.key < a.key;
  return false;
}

int main() {
    string s;
    int k = 0;
    while(getline(cin,s)) {
        if ( k != 0 ) printf("\n");
        memset(f,0,sizeof(f));
        vector<node> a;
        for(int i = 0; i < s.size(); ++i)
            f[s[i]]++; 
        for(int i = 0; i < N; ++i)
            if ( f[i] > 0 ) a.push_back(node(i,f[i]));
        sort(a.begin(),a.end());
        for(int i = 0; i < a.size(); ++i)
            printf("%d %d\n",a[i].key,a[i].value);        
        k++;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
