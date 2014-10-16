/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10810  C++  "Sorting, Merge Sort, Couting Inversions" */
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

typedef long long llong;
const int MAXN = 500020;
llong a[MAXN], b[MAXN];

llong merge_and_count(int lo, int mid, int hi) {
   llong res = 0LL;
   int i, j, k;
   for(i = lo; i <= hi; ++i)
      b[i] = a[i];
   i = k = lo; 
   j = mid + 1;
   while(i <= mid && j <= hi) {
      if(b[i] <= b[j])
         a[k++] = b[i++];
      else {
         a[k++] = b[j++];
         res += mid - i + 1;
      }
   }
   while(i<=mid)
      a[k++] = b[i++];
   return res;
}

llong sort_and_count(int lo, int hi) {
   llong res = 0LL;
   if(lo < hi) {
      int mid = lo + (hi - lo) / 2;      
      res =sort_and_count(lo, mid);
      res+=sort_and_count(mid + 1, hi);
      res+=merge_and_count(lo, mid, hi);      
   }
   return res;
}

int main(int argc, char *argv[]) {
   int N;
   while(1 == scanf("%d",&N)) {
      if(!N) break;
      for(int i = 0; i < N; ++i)
         scanf("%lld",&a[i]);
      printf("%lld\n", sort_and_count(0, N-1));
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

