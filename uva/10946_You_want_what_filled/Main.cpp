/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10946  C++  "DFS Flood Fill" */
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

#define N 51 
char v[N][N];
int D[N][N];
int cnt = 0;

void dfs(int i, int j, int n, int m, char c) {
    if ( i < 0 || i >= n || j < 0 || j >= m || D[i][j] != 0 || v[i][j] != c )
        return;
    cnt++;
    D[i][j] = 1;
    dfs(i+1,j,n,m,c);
    dfs(i-1,j,n,m,c);
    dfs(i,j+1,n,m,c);
    dfs(i,j-1,n,m,c);
}

struct Entry {
    string key;
    int w;
    bool operator<(const Entry &x)const {
        return w > x.w || w == x.w && key < x.key;
    }
};

int main() {
    int n,m;
    int k = 1;
    vector<Entry> lst;
    char buf[N];
    while ( scanf("%d %d\n",&n,&m) == 2 ) {
        if ( n == 0 && m == 0 ) break;
        for(int i = 0; i < n; ++i) {
            gets(buf);
            for(int j = 0; j < m; ++j)
                v[i][j] = buf[j];
        }
        memset(D,0,sizeof(D));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if ( v[i][j] != '.' ) {
                    dfs(i,j,n,m,v[i][j]);     
                    if ( cnt > 0 ) {
                        string k = tostr(v[i][j]);
                        Entry e;
                        e.key = k;
                        e.w = cnt;
                        lst.push_back(e);
                    }
                    cnt = 0;
                }   
            }
        }
        sort(lst.begin(),lst.end());
        printf("Problem %d:\n",k);
        for(int i = 0; i < lst.size(); ++i) {
            cout << lst[i].key << " " << lst[i].w;
            if ( i!=lst.size()-1 ) printf("\n");
        }
        printf("\n");
        lst.clear();
        k++;
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
