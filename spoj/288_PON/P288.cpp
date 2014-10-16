/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ PON C++ "Ad Hoc, Math, Prime, Miller-Rabin primality test" */
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

// to avoid long long overflow...
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1)
            x = (x+y)%c;
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

llong powmod(llong n, llong exp, llong mod) {
   if(exp==0LL) 
      return 1LL;
   if(exp&1LL) {
      return mulmod(n,powmod(n,exp-1,mod),mod);
   } else {
      llong t = powmod(n,exp>>1,mod);
      return mulmod(t,t,mod);
   }
}

bool miller(long long p,int k){
    if(p<2) return false;
    if(p!=2 && p%2==0) return false;
    long long s=p-1;
    while(s%2==0) s/=2;
    for(int i=0; i < k; ++i){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=powmod(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
   int TC;
   llong n;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%lld",&n);
      // Miller-Rabin primality test, iteration signifies the accuracy of the test
      bool isprime = miller(n,2);
      if(isprime) puts("YES");
      else puts("NO");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
