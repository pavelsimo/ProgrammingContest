#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int a, b, c;
   cin >> a >> b >> c;
   cout << (c + a - 1) * (b + a - 1) - (a)*(a-1) << endl;
   return 0;
}

