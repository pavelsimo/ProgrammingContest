/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11078  C++  "Math, Pascal Triangle" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

int A[12][12];

int main(int argc, char *argv[]) {
   int TC;
   scanf("%d",&TC);
   while(TC-- > 0) {
      for(int i = 1, r = 0; i <= 5; ++i, r+=2) {
	 for(int j = 0, c = 0; j < i; ++j, c+=2) {
	    scanf("%d",&A[r][c]);
	 }
      }
      for(int i = 0; i < 9; i += 2) {
	 for(int j = 0; j <= i; j += 2) {
	    A[i+2][j+1] = (A[i][j] - A[i+2][j] - A[i+2][j+2]) / 2;
	    A[i+1][j] = A[i+2][j] + A[i+2][j+1];
	    A[i+1][j+1] = A[i+2][j+2] + A[i+2][j+1];
	 }
      }
      for(int i = 0; i < 9; ++i) {
	 for(int j = 0; j <= i; ++j) {
	    if(j > 0) putchar(' ');
	    printf("%d",A[i][j]);
	 }
	 printf("\n");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
