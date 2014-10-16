/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10608  C++  "Disjoint Sets" */
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
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(ALL(container),element) != container.end()) 
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct DisjointSet {
    map<int,int> parent;
    map<int,int> rank;
    
    void make_set(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
    
    int find_set(int x) {
        int& p = parent[x];
        if ( x != p )
            p = find_set(p); // path compresion
        return p;
    }
    
    bool union_set(int x, int y) {
        int x_root = find_set(x);
        int y_root = find_set(y);
        if ( x_root == y_root )
            return false;
        link(x_root,y_root);
        return true;
    }
    
    void link(int x, int y) {
        if ( rank[x] > rank[y] ) {
            parent[y] = x;
        } else {
            parent[x] = y;
            if ( rank[x] == rank[y] )
                rank[y]++;
        }
    }
};

int main() {
    int ncases, n, m, x, y;
    scanf("%d\n",&ncases);
    for(int i = 0; i < ncases; ++i) {
        map<int,int> score;
        DisjointSet dset;      
        scanf("%d %d\n",&n,&m);
        for(int j = 1; j <= n; ++j)
            dset.make_set(j);
        for(int j = 0; j < m; ++j) { 
            scanf("%d %d\n",&x,&y);
            dset.union_set(x,y);
        }
        for(int j = 1; j <= n; ++j) 
            dset.find_set(j);       
        for(int j = 1; j <= n; ++j) {
            int p = dset.parent[j];
            score[p] = score[p] + 1;
        }
        int res = 0;
        FORE(score,it)
            res = max(res,it->second);
        printf("%d\n",res);
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */

