#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   int n;
   cin >> n;
   if(n >= 4 && n % 2 == 0) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}

