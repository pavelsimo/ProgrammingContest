/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MEDIAN12 C++ "Ad Hoc" */
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

int a[55];
int main(int argc, char *argv[]) {
   int TC, n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      for(int i = 0; i < n; ++i)
         scanf("%d",&a[i]);
      sort(a,a+n);
      if(n%2!=0) printf("%d\n",a[n/2]);
      else puts("-1");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
