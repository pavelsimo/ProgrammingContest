#include <iostream>

using namespace std;

int A[32], lo[32], hi[32];

int main(int argc, char *argv[]) {
   int d, sum;
   cin >> d >> sum;
   for(int i = 0; i < d; ++i) {
      cin >> lo[i] >> hi[i];
      A[i] = lo[i];
      sum -= lo[i];
   }
   if(sum < 0) {
      cout << "NO" << endl;
      return 0;
   }
   for(int i = 0; i < d; ++i) {
      if(sum > 0) {
         int diff = hi[i] - A[i];
         if(sum >= diff) {
            A[i] = hi[i];
            sum -= diff;
         } else {
            A[i] += sum;
            sum = 0;
         }
      }
   }
   if(sum > 0) {
      cout << "NO" << endl;
      return 0;
   }
   cout << "YES" << endl;
   for(int i = 0; i < d; ++i)
      cout << A[i] << ' ';
   cout << endl;
   return 0;
}

