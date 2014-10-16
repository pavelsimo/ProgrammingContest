#include <iostream>

using namespace std;

int a[100002], alice[100002], bob[100002];

int main(int argc, char *argv[]) {
   int n, apts, bpts;
   cin >> n;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   alice[0] = a[0];
   for(int i = 1; i < n; ++i)
      alice[i] = a[i] + alice[i-1];
   bob[n - 1] = a[n - 1];
   for(int i = n - 2; i >= 0; --i)
      bob[i] = a[i] + bob[i+1];
   apts = bpts = 0;
   for(int i = 0; i < n; ++i) {
      if(alice[i] <= bob[i]) apts++;
      else bpts++;
   }
   cout << apts << ' ' << bpts << endl;
   return 0;
}

