/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11388  C++  "Math, GCD, LCM" */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

vector<llong> fact(llong n) {
   vector<llong> res;
   llong x = n;
   res.push_back(1LL);
   for(llong i = 2LL; i * i <= x; ++i) {
      while(x % i == 0LL) {
         res.push_back(i);
         x/=i;
      }
   }
   if(x > 1LL) res.push_back(x);
   return res;
}

int main(int argc, char *argv[]) {
   int TC;
   llong a, b;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld%lld",&a,&b);
      vector<llong> apf = fact(a);
      vector<llong> bpf = fact(b);
      bool found = true;
      for(int i = 0; i < sz(apf); ++i) {
         if(!binary_search(all(bpf), apf[i])) {
            found = false;
            break;       
         }
      }
      if(found) printf("%lld %lld\n",a, b);
      else printf("-1\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
