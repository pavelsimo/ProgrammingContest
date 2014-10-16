#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int n, m;
   cin >> n >> m;
   int pos = (m + 1)/2;
   int l = pos;
   int r = pos + 1;
   for(int i = 0; i < n; ++i) {
      if((m % 2 == 0 && abs(l - pos) < abs(r - pos)) 
         || (m % 2 == 1 && abs(l - pos) <= abs(r - pos))) {
         if(l > 0) {
            cout << l << endl;
            l--;            
         } else if(r <= m) {
            cout << r << endl;
            r++;            
            l = pos;
         } else {
            cout << pos << endl;
            l = r = pos;
            l--;
            r++;
         }
      } else {
         if(r <= m) {
            cout << r << endl;
            r++;            
         } else if(l > 0) {
            cout << l << endl;
            l--;
            r = pos + 1;              
         }  else {
            cout << pos << endl;
            l = r = pos;
            l--;
            r++;
         }
      }
   }
   return 0;
}

