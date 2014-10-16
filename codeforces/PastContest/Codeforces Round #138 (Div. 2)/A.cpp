#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int abc, ab, ac, bc, a, b, c;
   cin >> ab >> ac >> bc;
   abc = (int) sqrt(1.0 * ab * ac * bc);
   a = abc / bc;
   b = abc / ac;
   c = abc / ab;
   cout << 4 * (a + b + c) << endl;
   return 0;
}

