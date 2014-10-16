#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) { 
   int A[4];
   bool issegment = false, istriangle = false;
   cin >> A[0] >> A[1] >> A[2] >> A[3];
   sort(A, A + 4);
   for(int i = 0; i < 4; ++i) {
      for(int j = i + 1; j < 4; ++j) {
         for(int k = j + 1; k < 4; ++k) {
            if(A[i] + A[j] > A[k]) istriangle = true;
            else if(A[i] + A[j] == A[k]) issegment = true;
         }
      }   
   }
   if(istriangle) cout << "TRIANGLE" << endl;
   else if(issegment) cout << "SEGMENT" << endl;
   else cout << "IMPOSSIBLE" << endl;
   return 0;
}

