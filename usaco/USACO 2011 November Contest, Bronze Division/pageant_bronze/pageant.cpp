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

typedef pair<int,int> PII;
const int MAXN = 60, INF = 10000;
int N, M;
int ind;
char board[MAXN][MAXN];
vector<PII> A[2];

void dfs(int i, int j) {
   if(i < 0 || i >= N || j < 0 || j >= M || board[i][j] != 'X') 
      return;
   board[i][j] = '1' + ind;
   A[ind].push_back(make_pair(i,j));
   dfs(i + 1, j);
   dfs(i - 1, j);
   dfs(i, j + 1);
   dfs(i, j - 1);
}

int main() {
   //freopen("pageant.in", "r", stdin);
   //freopen("pageant.out", "w", stdout);
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
   int res = INF;
   for(int i = 0; i < sz(A[0]); ++i) {
      for(int j = 0; j < sz(A[1]); ++j) {
         res = min(res, abs(A[0][i].first - A[1][j].first) + abs(A[0][i].second - A[1][j].second));
      }
   }
   printf("%d\n",res - 1);
   return 0;
}
