#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int a, b, c, t;
   cin >> a >> b >> c;
   for(t = 1; true; ++t) {
      // remaining data after wait for t seconds
      int r = (a * c) - (t * b);
      if(r <= c*b) break;
   }
   cout << t << endl;
   return 0;
}

