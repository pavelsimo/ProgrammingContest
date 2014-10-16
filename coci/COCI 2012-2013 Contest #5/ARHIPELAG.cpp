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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


typedef long long llong;

const int MAXN = 32;
bool flooded[MAXN][MAXN];
char B[MAXN][MAXN];

int main(int argc, char *argv[]) { 
   int R, C, mi_i, mi_j , ma_i, ma_j;
   scanf("%d%d",&R,&C);
   for(int i = 0; i < MAXN; ++i) {
      for(int j = 0; j < MAXN; ++j) {
         B[i][j] = '.';
      }
   }
   mi_i = MAXN; mi_j = MAXN;
   ma_i = 0; ma_j = 0;
   for(int i = 1; i <= R; ++i) scanf("%s",B[i] + 1);
   for(int i = 1; i <= R; ++i) {
      for(int j = 1; j <= C; ++j) {
         if(B[i][j] == 'X') {
            int cnt = 0;
            if(B[i - 1][j] == '.') cnt++;
            if(B[i + 1][j] == '.') cnt++;
            if(B[i][j - 1] == '.') cnt++;
            if(B[i][j + 1] == '.') cnt++;
            if(cnt >= 3) flooded[i][j] = true;
         }
      }
   }
   for(int i = 1; i <= R; ++i) {
      for(int j = 1; j <= C; ++j) {
         if(flooded[i][j]) B[i][j] = '.';
      }
   }
   for(int i = 1; i <= R; ++i) {
      for(int j = 1; j <= C; ++j) {
         if(B[i][j] == 'X') {
             mi_i = min(mi_i, i); mi_j = min(mi_j, j);
             ma_i = max(ma_i, i); ma_j = max(ma_j, j);
          }
      }
   }
   for(int i = mi_i; i <= ma_i; ++i) {
      for(int j = mi_j; j <= ma_j; ++j) {   
         printf("%c", B[i][j]);
      }
      printf("\n");
   }
   return 0;
}

