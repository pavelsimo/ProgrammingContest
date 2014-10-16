/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  993  C++  "Math, Prime Factor" */
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

char res[1024];
const int MAXP = 8;
const int F[] = {9,8,6,4,2,3,5,7};

int main(int argc, char *argv[]) {
   int TC, n, m;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d",&n);
      if(n >= 10) {
         m = 0;
         for(int i = 0; i < MAXP; ++i) 
            while(n % F[i] == 0) 
               res[m++] = ('0'+F[i]), n/=F[i];
         res[m] = '\0';
         if(n > 1) {
            puts("-1");  
         } else {
            sort(res, res + m);
            puts(res);    
         }
      } else {
         printf("%d\n",n);
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
