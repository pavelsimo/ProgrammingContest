#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

typedef long long llong;

vector<llong> F;
int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   llong n;
   cin >> n;
   llong a = 0LL;
   llong b = 1LL;
   F.push_back(a); F.push_back(b);
   for(llong i = 0; true; ++i) {
      llong c = a + b;
      if(c > n) break;
      F.push_back(c);
      a = b;
      b = c;
   }
   for(int i = 0; i < sz(F); ++i) {
      for(int j = 0; j < sz(F); ++j) {
         if(n - F[i] - F[j] >= 0) {
            if(binary_search(F.begin(), F.end(), n - F[i] - F[j])) {
               cout << F[i] << ' ' << F[j] << ' ' << n - F[i] - F[j] << endl;
               return 0;
            }            
         }
      }
   }
   cout << "I'm too stupid to solve this problem" << endl;
   return 0;
}
