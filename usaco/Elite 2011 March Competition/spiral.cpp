/*
ID: 13
PROG: spiral
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define pb push_back

int N;
const int maxn = 760;
int a[maxn][maxn];
int dr[] = {+0,+1,-1,+0};
int dc[] = {+1,+0,+0,-1};

int main() {
   freopen("spiral.in", "r", stdin);
   freopen("spiral.out", "w", stdout);
   scanf("%d",&N);
   int cnt = 1;
   int r = 0;
   int c = 0;
   memset(a,-1,sizeof(a));
   a[r][c] = cnt;
   while(true) {
    bool move = false;
    for(int d = 0; d < 4; ++d) {
       while(true) {
         int nr = r+dr[d];
         int nc = c+dc[d];
         if(nr < 0 || nr >= N || nc < 0 || nc >= N || a[nr][nc]>0) break;
         r+=dr[d];
         c+=dc[d];
         a[r][c] = ++cnt;
         move=true;
       }
    }
    if(!move)break;
   }
   for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
       if(j > 0) putchar(' ');
       printf("%d",a[i][j]);
    }
    putchar('\n');
   }
   return 0;
}
