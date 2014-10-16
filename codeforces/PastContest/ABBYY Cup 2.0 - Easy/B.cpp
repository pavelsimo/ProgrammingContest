#include <iostream>

using namespace std;

typedef long long llong;

int main(int argc, char *argv[]) {
   llong n, res;
   cin >> n;
   res = n;
   for(llong x = 2; x * x <= n; ++x) {
      while(n % x == 0LL) {
         n/=x;
         res+=n;
      }
   }
   if(n > 1) res++;
   cout << res << endl;
   return 0;
}

