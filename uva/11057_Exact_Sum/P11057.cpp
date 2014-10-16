/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11057  C++  "Binary Search" */
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

const int MAXN = 10002, INF = 10000000;
int a[MAXN];

int main(int argc, char *argv[]) {
   int N, M, b1, b2;
   while(scanf("%d",&N)==1) {
      for(int i = 0; i < N; ++i)
         scanf("%d",&a[i]);
      scanf("%d",&M);
      sort(a,a+N);
      b1 = b2 = INF;
      for(int i = 0; i < N; ++i) {
         if(binary_search(a,a+N,M-a[i])) {
            if(b1==INF) {
               b1 = a[i];
               b2 = M-a[i];
            } else {
               if(abs(a[i]-M+a[i]) < abs(b1-b2)) {
                  b1 = a[i];
                  b2 = M-a[i];
               }
            }
         }
      }
      printf("Peter should buy books whose prices are %d and %d.\n\n",b1,b2);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
