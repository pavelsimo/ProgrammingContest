#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   int n, a, res;
   cin >> n;
   res = 0;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {   
         cin >> a;
         if(i == j || i == n/2 || j == n/2 || n - i - 1 == j) 
            res+=a;
      }
   }
   cout << res << endl;
   return 0;
}

