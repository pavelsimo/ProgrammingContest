/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12463  C++  "Combinatorics" */
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long llong;

/*
 one red hat, 
 two T-shirts (one blue and one green)
 one pair of pants (black)
 two pairs of socks (one white pair and one orange pair)
 two pairs of shoes (one brown pair and the other one yellow) 

*/
int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   llong a, b, c, d, e;
   while(cin >> a >> b >> c >> d >> e) {
      if(!a && !b && !c && !d && !e) break;
      cout << 4 * a * b * c * d * e << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

