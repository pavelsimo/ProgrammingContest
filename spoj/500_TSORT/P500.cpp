/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ TSORT C++ "Ad Hoc" */
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
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

int N;
vector<int> A;

int main(int argc, char *argv[]) {
   int x;
   scanf("%d",&N);
   while(N-- > 0) {
      scanf("%d",&x);   
      A.push_back(x);
   }
   sort(all(A));
   for(int i = 0; i < sz(A); ++i)
      printf("%d\n",A[i]);
   return 0;
}
/* @END_OF_SOURCE_CODE */

