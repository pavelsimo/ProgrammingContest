#include <iostream>

using namespace std;

typedef long long llong;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC;
   llong n;
   cin >> TC;
   while(TC-- > 0) {  
      cin >> n;
      if((n + 1) % 4 == 0) cout << n + 1 << endl;
      else if((n + 1) % 2 == 0) cout << 2*n + 1 << endl;
      else cout << 4*n + 1 << endl;
   }
   return 0;
}

