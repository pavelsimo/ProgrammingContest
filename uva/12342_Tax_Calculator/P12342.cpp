/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12342  C++  "Ad Hoc" */
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

int main(int argc, char *argv[]) {
   int TC;
   double N, tax;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lf",&N);
      tax = 0LL;
      bool payable_tax = false;
      
      // The first 180,000/- of income is tax free.
      N = max(0.0, N - 180000); 
      
      // Next 300,000/- will have 10% tax.
      if(N > 0) tax += (min(N,300000.0) * 10)/100.0, payable_tax = true; 
      N = max(0.0, N - 300000);
      
      // Next 400,000/- will have 15% tax.
      if(N > 0) tax += (min(N,400000.0) * 15)/100.0;
      N = max(0.0, N - 400000);
      
      // Next 300,000/- will have 20% tax.
      if(N > 0) tax += (min(N,300000.0) * 20)/100.0;
      N = max(0.0, N - 300000);
      
      // The rest will have 25% tax.
      if(N > 0) tax += (N * 25LL)/100.0;
      tax = ceil(tax);
      if(payable_tax) tax = max(2000.0, tax);
      printf("Case %d: %.0lf\n",tc,tax);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

