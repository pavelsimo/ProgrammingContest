/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10443  C++  "Ad Hoc" */
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

const int MAXN = 110;
char A[MAXN][MAXN], B[MAXN][MAXN];

bool check(char p1, char p2) {
   if(p1=='R' && p2=='S') return true;
   if(p1=='S' && p2=='P') return true;
   if(p1=='P' && p2=='R') return true;
   return false;
}

int main(int argc, char *argv[]) {
   int TC, N, M, D;
   scanf("%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      scanf("%d%d%d",&N,&M,&D);
      for(int i = 0; i < N; ++i)
         scanf("%s",A[i]);
      while(D-- > 0) {
         for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
               B[i][j] = A[i][j];
               if(j + 1 < M  && check(A[i][j+1],A[i][j])) B[i][j] = A[i][j+1];
               if(j - 1 >= 0 && check(A[i][j-1],A[i][j])) B[i][j] = A[i][j-1];
               if(i + 1 < N  && check(A[i+1][j],A[i][j])) B[i][j] = A[i+1][j];
               if(i - 1 >= 0 && check(A[i-1][j],A[i][j])) B[i][j] = A[i-1][j];
            }
         }
         for(int i = 0; i < N; ++i) 
            for(int j = 0; j < M; ++j)
               A[i][j] = B[i][j];
      }
      for(int i = 0; i < N; ++i) 
         puts(A[i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
