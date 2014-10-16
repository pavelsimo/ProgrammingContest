/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  496  C++  "Math, Sets" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

double X[1002], Y[1002];

int main(int argc, char *argv[]) {
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      for(int i = 0; i < N; ++i) {
         scanf("%lf%lf",&X[i],&Y[i]);
      }
      sort(X, X + N); 
      sort(Y, Y + N);
      printf("%.4lf\n",fabs(X[N-1] - X[0])*fabs(Y[N-1] - Y[0]));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
