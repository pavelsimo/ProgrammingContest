/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  15240 10009  C++  "Graph Theory BFS" */
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

#define N 26
// adjacent matrix
int adjMatrix[N][N];
int D[N];
int parents[N];

int getAdjUnvisitedVertex(int v) {
    for(int i = 0; i < N; ++i) {
        if ( adjMatrix[v][i] == 1 && D[i] == -1 )
            return i;
    }
    return -1;
}

void clean() {
    memset(D, -1, sizeof(D));  
    memset(parents, -1, sizeof(parents));  
}

void bfs(int begin, int end) {
     queue<int> q;
     q.push(begin);
     D[begin] = 0;
     while ( !q.empty() ) {
         int s = q.front();
         q.pop();
         if ( s == end ) break;
         int ns;
         while ((ns = getAdjUnvisitedVertex(s)) != -1 ) {
             q.push(ns);
             D[ns] = D[s]+1;
             parents[ns] = s;
         }
     }
}

int main() {
    int ncases;
    int m, n;
    char s1[128];
    char s2[128];
    clean();
    scanf("%d\n",&ncases);
    for(int k = 0; k < ncases; ++k) {
         scanf("%d %d\n",&m,&n);       
         for(int i = 0; i < m; ++i) {
             scanf("%s %s\n", &s1, &s2);
             adjMatrix[s1[0]-'A'][s2[0]-'A'] = 1;
             adjMatrix[s2[0]-'A'][s1[0]-'A'] = 1;
         }
         for(int i = 0; i < n; ++i) {
             string res = "";
             scanf("%s %s\n", &s1, &s2);
             bfs(s1[0]-'A',s2[0]-'A');
             int x = s2[0]-'A';
             int tx = s1[0]-'A';
             res = s2[0] + res;
             while ( x != tx ) {
                 x = parents[x];
                 char c = x+'A';
                 res = c + res;  
             }
             cout << res;
             printf("\n");
             clean();
         } 
         // clean adjancent matrix
         memset(adjMatrix, 0, sizeof(adjMatrix));
         if ( ncases-1 != k )
            printf("\n");
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
