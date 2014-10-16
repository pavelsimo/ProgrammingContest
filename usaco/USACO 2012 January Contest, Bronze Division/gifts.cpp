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

struct Gift {
   llong id, price, shipping;   
   Gift(llong _id = 0, llong _price = 0, llong _shipping = 0):
      id(_id), price(_price), shipping(_shipping) {}
   bool operator<(const Gift &T) const {
      if(T.price + T.shipping != price + shipping)
         return price + shipping < T.price + T.shipping;
      if(T.price != price) 
         return price > T.price;
      return shipping < T.shipping;
   }
};

const int MAXN = 1002;
Gift A[MAXN], B[MAXN];
bool seen[MAXN];
llong N, budget;

int main() {
   //freopen("gifts.in", "r", stdin);
   //freopen("gifts.out", "w", stdout);
   scanf("%lld%lld",&N,&budget);
   int i, res;
   memset(seen, false, sizeof(seen));
   for(i = 0; i < N; ++i) {
      scanf("%lld%lld",&A[i].price, &A[i].shipping);
      A[i].id = B[i].id = i;
      B[i].price = A[i].price/2;
      B[i].shipping = A[i].shipping;
   }
   sort(A, A + N);
   sort(B, B + N);
   for(res = 0; res < N; ++res) {
      if(budget >= A[res].price + A[res].shipping) {
         seen[A[res].id] = true;
         budget-=A[res].price + A[res].shipping;
      } else {
         break;
      }
   }
   for(i = 0; i < N; ++i) {
      if(!seen[B[i].id] && budget >= B[i].price + B[i].shipping) {
         res++;
         break;
      }
   }
   printf("%d\n",res);
   return 0;
}
