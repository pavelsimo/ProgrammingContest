/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ C++ "Binary Search, lower_bound, upper_bound, subset sum" */
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

typedef long long llong;
const int MAXN = 36;
int L[MAXN];

int main(int argc, char *argv[]) {
   int N, A, B;
   llong ans = 0LL;
   vector<int> s1, s2, t1;
   scanf("%d%d%d",&N,&A,&B);
   for(int i = 0; i < N; ++i) scanf("%d",&L[i]);
   int K = N/2;
   for(int i = 0; i < K; ++i) s1.push_back(L[i]);
   for(int i = K; i < N; ++i) s2.push_back(L[i]);
   
   int M = 1 << sz(s1);
   for(int j = 0; j < M; ++j) {
      int sum = 0;
      for(int i = 0; i < sz(s1); ++i) {
         if(j&(1<<i)) {
            sum+=s1[i];
         }
      }
      t1.push_back(sum);
   }
   
   sort(all(t1));
   
   M = 1 << sz(s2);
   int low, upper;
   for(int j = 0; j < M; ++j) {
      int sum = 0;
      for(int i = 0; i < sz(s2); ++i) {
         if(j&(1<<i)) {
            sum+=s2[i];
         }
      }
      low   = int(lower_bound(all(t1),A-sum) - t1.begin());
      upper = int(upper_bound(all(t1),B-sum) - t1.begin());
      ans+=upper-low;
   }
   
   printf("%lld\n",ans);
   return 0;
}
/* @END_OF_SOURCE_CODE */
