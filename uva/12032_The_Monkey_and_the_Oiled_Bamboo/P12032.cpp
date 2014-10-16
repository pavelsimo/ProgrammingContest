/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12032  C++  "Ad Hoc, Math" */
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

const int MAXN = 100010;
int A[MAXN];

int main(int argc, char *argv[]) {
   int TC, res, cnt, N, best;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%d",&N);
      for(int i = 1; i <= N; ++i)
         scanf("%d",&A[i]);
      A[0] = 0;
      res = cnt = best = 0;
      for(int i = 0; i < N; ++i)
         best = res = max(res,A[i+1]-A[i]);
      bool ok = true;
      for(int i = 0; i < N; ++i) {
         if(A[i+1]-A[i] > best) {
            ok = false;
            break;
         }
         if(A[i+1]-A[i]==best) best--;
      }
      if(!ok) res++;
      printf("Case %d: %d\n",tc,res);   
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
