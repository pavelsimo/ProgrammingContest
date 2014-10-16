#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

int main(int argc, char *argv[]) {
   int n;
   double res, k, p;
   cin >> n;
   res = 0;
   k = 100.0 / n;
   for(int i = 0; i < n; ++i) {
      cin >> p;
      res += k * p/100.0;
   }
   cout << res << endl;
   return 0;
}
