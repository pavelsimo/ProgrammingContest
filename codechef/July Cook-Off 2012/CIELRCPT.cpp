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

int main() { 
   int TC, p, res;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&p);
      res = 0;
      while(p >= 2048) p-=2048, res++;
      res+=__builtin_popcount(p);
      printf("%d\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
