/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10515  C++  "Number Theory, Math, Power" */
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

#define sz(a) int((a).size())

int main(int argc, char *argv[]) {
   int m, n, res;
   string a, b;
   while(cin >> a >> b) {
      if(a == "0" && b == "0") break;
      m = a[sz(a)-1]-'0';
      if(b == "0") {
         res = 1;
      } else { 
         if(sz(b) > 1) n = (b[sz(b)-2]-'0')*10 + (b[sz(b)-1]-'0');
         else n = (b[sz(b)-1]-'0');
         res = m;
         for(int i = 1; i < n; ++i)
            res = (res * m) % 10;                  
      }
      printf("%d\n",res);
   }   
   return 0;
}
/* @END_OF_SOURCE_CODE */

