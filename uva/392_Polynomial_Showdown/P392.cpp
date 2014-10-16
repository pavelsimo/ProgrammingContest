/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  392  C++  "Simple Math, Format Output" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int N = 9;
int C[N + 1];

int main(int argc, char *argv[]) {
   int i_constant_term;
   bool leading_term, non_constant_eq;
   while(9 == scanf("%d%d%d%d%d%d%d%d%d",&C[0],&C[1],&C[2],&C[3],&C[4],&C[5],&C[6],&C[7],&C[8])) {
      leading_term = true;
      non_constant_eq = false;
      i_constant_term = N - 1;
      for(int i = 0; i < N; ++i) {
         if(C[i] || (i == i_constant_term && !non_constant_eq)) {
            bool positive = (C[i] >= 0);
            int c = abs(C[i]);
            if(i != i_constant_term) non_constant_eq = true;
            if(leading_term) {
               if(!positive) printf("-");
               leading_term = false;
            } else {
               putchar(' ');
               if(positive) putchar('+');
               else putchar('-');
               putchar(' ');
            }
            if(c != 1 || i == i_constant_term) printf("%d",c);
            if(i != i_constant_term) putchar('x');
            if(N - i > 2) printf("^%d",N-i-1); 
         }
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
