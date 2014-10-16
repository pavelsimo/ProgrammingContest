/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1225  C++  "Ad Hoc, Math" */
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

const int MAXN = 10002;
int A[MAXN][10];

int main(int argc, char *argv[]) {
   memset(A,0,sizeof(A));
   for(int i = 1; i < 10000; ++i) {
      int j = i;
      while(j > 0)
         A[i][j%10]++, j/=10;
      A[i][0] += A[i - 1][0];
      A[i][1] += A[i - 1][1];
      A[i][2] += A[i - 1][2];
      A[i][3] += A[i - 1][3];
      A[i][4] += A[i - 1][4];
      A[i][5] += A[i - 1][5];
      A[i][6] += A[i - 1][6];
      A[i][7] += A[i - 1][7];
      A[i][8] += A[i - 1][8];
      A[i][9] += A[i - 1][9];
   }
   int TC, N;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&N);
      printf("%d %d %d %d %d %d %d %d %d %d\n",
         A[N][0],A[N][1],A[N][2],A[N][3],A[N][4],A[N][5],A[N][6],A[N][7],A[N][8],A[N][9]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
