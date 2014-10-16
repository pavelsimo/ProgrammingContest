/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11309  C++  "Ad Hoc, Palindromes" */
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

char s[32], buf[32];

bool ispal(char *s) {
   int lo = 0;
   int hi = strlen(s) - 1;
   while(lo < hi) {
      if(s[lo]!=s[hi]) 
         return false;
      lo++;
      hi--;
   }
   return true;
}

int main(int argc, char *argv[]) {
   int TC, H, M;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      sscanf(buf,"%d:%d",&H,&M);
      while(true) {
         M++;
         if(M==60) H++, M = 0;
         if(H==24) H = 0;         
         if(H==0) sprintf(s,"%d",M);
         else sprintf(s,"%d%02d",H,M);         
         if(ispal(s)) {
            printf("%02d:%02d\n",H,M);
            break;      
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
