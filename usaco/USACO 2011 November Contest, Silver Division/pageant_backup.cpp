/*
ID: 11
PROG: file
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef pair<int,int> Point;
const int INF = 0x3f3f3f3f;
int N, M, ind;
char board[60][60];
vector<Point> P[4];

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= M || board[i][j]!='X') return;
   board[i][j] = '@';
   P[ind].push_back(Point(i,j));
   dfs(i + 1, j);
   dfs(i, j + 1);
   dfs(i - 1, j);
   dfs(i, j - 1);
}

int dist(Point a, Point b) {
   return abs(a.first - b.first) + abs(a.second - b.second) - 1;
}

int main() {
    //freopen("pageant.in", "r", stdin);
    //freopen("pageant.out", "w", stdout);
    int res = 0;
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; ++i)
      scanf("%s",board[i]);
    ind = 0;
    for(int i = 0; i < N; ++i) {
       for(int j = 0; j < M; ++j) {
          if(board[i][j] == 'X') {
             dfs(i,j);
             ind++;
          }
       }
    }
    vector<int> a;
    for(int src = 0; src < ind; ++src) {
       for(int dst = src + 1; dst < ind; ++dst) {
          int d = INF;
          for(int i = 0; i < sz(P[src]); ++i) {
             for(int j = 0; j < sz(P[dst]); ++j) {
                d = min(d,dist(P[src][i],P[dst][j]));
             }
          }
          DEBUG(d);
          a.push_back(d);
       }
    }
    sort(all(a));
    for(int i = 0; i < ind - 1; ++i) res+=a[i];
    printf("%d\n",res);
    return 0;
}
