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
int N, M, label;
char board[60][60];
int a[60][60];
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};


void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= M || board[i][j]!='X') return;
   board[i][j] = '@';
   a[i][j] = label;
   for(int d = 0; d < 4; ++d)
      dfs(i + dx[d], j + dy[d]);
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
    memset(a,0,sizeof(a));
    label = 1;
    for(int i = 0; i < N; ++i) {
       for(int j = 0; j < M; ++j) {
          if(board[i][j] == 'X') {
             dfs(i,j);
             label++;
          }
          printf("%02d ",a[i][j]);
       }
       putchar('\n');
    }

    printf("%d\n",res);
    return 0;
}
