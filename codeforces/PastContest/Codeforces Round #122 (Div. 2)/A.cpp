#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int n, k, res;
   cin >> n >> k;
   res = k;
   for(int x = 0; x <= n; ++x) {
      for(int y = 0; y <= n; ++y) {
         for(int z = 0; z <= n; ++z) {
            for(int w = 0; w <= n; ++w) {  
               int sum = 2*w + 3*x + 4*y + 5*z;
               if(x + y + z + w == n && sum == k) 
                  res = min(res, w);
            }
         }
      }
   }
   cout << res << endl;
   return 0;
}

