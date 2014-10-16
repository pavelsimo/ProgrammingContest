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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

template<typename INT>
INT gcd(INT a, INT b) {
   if (a < 0) a = -a;
   if (b < 0) b = -b;
   if (a < b) swap(a, b);
   while (b > 0) {
      INT t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

template<typename INT>
INT lcm(INT a, INT b) {
   return a / gcd(a,b) * b;
}

vector<llong> factorization(llong n) {
   vector<llong> res;
   for(llong i = 2; i*i <= n; ++i) {
      while(n % i == 0) {
         res.push_back(i);
         n/=i;
      }
   }
   if(n > 1) res.push_back(n);
   return res;
}

int print(llong n) {
   vector<llong> PF = factorization(n);
   for(int i = 0; i < sz(PF); ++i)
      cout << PF[i] << ' ';
   cout << endl;
   return 0;
}

int main(int argc, char *argv[]) {
   llong a = 160, b = 0, c = 90;
   DEBUG(a);
   print(a);
   DEBUG(b);
   print(b);
   DEBUG(c);
   print(c);
   cout << "x*y = a + b*lcm(x,y) + c*gcd(x,y)" << endl;
   cout << endl;
   for(llong x = 1; x <= 1000; ++x) {
      for(llong y = 1; y <= 1000; ++y) {   
         if(x * y == a + b*lcm(x,y) + c*gcd(x,y)) {
            printf("x=%lld : ",x);
            print(x);
            printf("y=%lld : ",y);
            print(y);
            printf("lcm(x,y)=%lld : ",lcm(x,y));
            print(lcm(x,y));
            printf("gcd(x,y)=%lld : ",gcd(x,y));
            print(gcd(x,y));
            cout << endl;
         }
      }
   }
   
   /*
   int TC;
   llong a, b, c;
   cin >> TC;
   while(TC-- > 0) {
      cin >> a >> b >> c;
      
      
   }
   */
   return 0;
}

