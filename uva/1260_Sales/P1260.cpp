/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1260  C++  "Ad Hoc" */
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

const int MAXN = 1002;
int a[MAXN];

int main(int argc, char *argv[]) {
   int TC, n, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      res = 0;
      for(int i = 0; i < n; ++i) {
         scanf("%d",&a[i]);
         for(int j = 0; j < i; ++j) {
            if(a[j] <= a[i]) 
               res++;
         }
      }
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
