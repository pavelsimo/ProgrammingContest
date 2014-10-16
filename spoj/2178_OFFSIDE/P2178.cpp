/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ OFFSIDE C++ "Ad Hoc, Simulation" */
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

const int MAXN = 20;
int A[MAXN], D[MAXN], N, M;

bool isoffside() {
   for(int i = 0; i < N; ++i) {
      int cnt = 0;
      for(int j = 0; j < 2; ++j)
         if(D[j] > A[i]) cnt++;
      if(cnt > 0) return true;
   }
   return false;
}

int main(int argc, char *argv[]) {
   
   while(cin >> N >> M) {
      if(!N && !M) break;  
      for(int i = 0; i < N; ++i)
         cin >> A[i];
      for(int i = 0; i < M; ++i)
         cin >> D[i];   
      sort(D, D + M);
      if(isoffside()) puts("Y");
      else puts("N");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

