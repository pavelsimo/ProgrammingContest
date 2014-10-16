#include <iostream>

using namespace std;

typedef long long llong;

llong gcd(llong a, llong b) {
   if (a < b) swap(a, b);
   while (b > 0) {
      llong t = b;
      b = a % b;
      a = t;
   }
   return a > 0 ? a : 1;
}

llong lcm(llong a, llong b) {
   return a / gcd(a,b) * b;
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC;
   llong n;
   cin >> TC;
   while(TC-- > 0) {  
      cin >> n;
      cout << lcm(n + 1LL, n * 4LL)/(n + 1LL) + 1LL << endl;
   }
   return 0;
}

