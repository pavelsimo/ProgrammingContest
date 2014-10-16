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
llong C[10002][10002];

llong nCr(int n, int r) {
   for(int i=0; i<=n; i++) {
      for (int k=0; k<=r && k<=i; k++) {
         if (k==0 || k==i)
            C[i][k] = 1LL;
         else
            C[i][k] = (C[i-1][k-1] + C[i-1][k]);         
      }
   }
   return C[n][r];
}

pair<llong,llong> find(llong X) {
   for(llong i = 1; i <= 10000; ++i) {
      for(llong j = 1; j <= i; ++j) {
         if(C[i][j] == X)
            return make_pair(i,j);
      }
   }
   return make_pair(X,1);
}

int main(int argc, char *argv[]) {
   memset(C,0,sizeof(C));
   nCr(5000,5000);
   int TC;
   llong S, T;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lld",&S);
      T = 10000000000LL;
      for(llong i = 1; i*i <= S; ++i) {
         if(S % i == 0) {
            llong A = i;
            llong B = S/i;
            pair<llong,llong> X1 = find(A);
            pair<llong,llong> X2 = find(B);
            pair<llong,llong> X3 = make_pair(X1.first + X2.first, X1.second + X2.second);
            if(X3.second > X3.first) 
               swap(X3.first,X3.second);
            X3.first = X3.first - X3.second;
            T = min(T, min(A+B,X3.first+X3.second));
         }
      }
      printf("Case #%d: %lld\n",tc,T);
   }
   return 0;
}
