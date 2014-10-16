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

const int MAXN = 10020;
int A[MAXN];

int main() {
   //freopen("haybales.in", "r", stdin);
   //freopen("haybales.out", "w", stdout);
   int n, avg, res;
   scanf("%d",&n);
   res = avg = 0;
   for(int i = 0; i < n; ++i) {
      scanf("%d",&A[i]);
      avg+=A[i];
   }
   avg/=n;
   for(int i = 0; i < n; ++i) {
      if(A[i] > avg) 
         res+=A[i]-avg;
   }
   printf("%d\n",res);
   return 0;
}
