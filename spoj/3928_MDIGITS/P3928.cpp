/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MDIGITS C++ "Math, Number Theory" */
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
#include <regex.h>
 
using namespace std;
 
#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define BITCOUNT(x) __builtin_popcount(x)

int freq[10];

int main(int argc, char *argv[]) {
   int cnt = 0;
   for(int i = 1; i <= 10000; ++i) {
      int x = i;
      while(x > 0) {
         //if(i >= 100 && i <= 999 && x%10 == 1) 
         //   printf("%d\n",i), cnt++;
         freq[x%10]++;
         x/=10;  
      }      
      if(i % 9 == 0) {
         printf("%d: ",i);
         for(int j = 0; j < 10; ++j)
            printf("%d ",freq[j]);
         putchar('\n');
      }
      
   }
   DEBUG(cnt);
   return 0;
}
/* @END_OF_SOURCE_CODE */
