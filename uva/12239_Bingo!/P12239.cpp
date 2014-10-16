/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12239  C++  "Ad Hoc" */
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

const int MAXN = 102;
int A[MAXN], B[MAXN];

int main(int argc, char *argv[]) {
   int N, M; 
   while(2 == scanf("%d%d",&N,&M)) {
      if(!N && !M) break;
      for(int i = 0; i < M; ++i)
         scanf("%d",&A[i]);
      memset(B,false,sizeof(B));
      B[0] = true;
      for(int i = 0; i < M; ++i) {
         for(int j = i + 1; j < M; ++j) {
            B[abs(A[i]-A[j])] = true;
         }
      }
      bool found = true;
      for(int i = 0; i <= N; ++i) {
         if(!B[i]) {
            found = false;
            break;
         }
      }
      if(found) puts("Y");
      else puts("N");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
