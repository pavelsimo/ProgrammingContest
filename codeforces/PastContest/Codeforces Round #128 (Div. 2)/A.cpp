#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int x, t, a, b, da, db;
   cin >> x >> t >> a >> b >> da >> db;
   if(x == 0) {
      cout << "YES" << endl;
      return 0;
   }
   for(int t1 = 0; t1 < t; ++t1) {
      if(a - da*t1 == x || b - db*t1 == x) {
         cout << "YES" << endl;
         return 0;
      }
      for(int t2 = 0; t2 < t; ++t2) {
         if(a + b - da*t1 - db*t2 == x) {
            cout << "YES" << endl;
            return 0;
         }
      }
   }
   cout << "NO" << endl;
   return 0;
}

