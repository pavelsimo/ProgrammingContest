#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) int((a).size())

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int a, b, r;
   cin >> a >> b >> r;
   if(2*r <= a && 2*r <= b)
      cout << "First" << endl;
   else 
      cout << "Second" << endl;
   return 0;
}
