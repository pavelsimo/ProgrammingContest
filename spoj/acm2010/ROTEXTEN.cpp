/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ROTEXTEN C++ "Ad Hoc" */
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

char dec(char ch) {
   if(isdigit(ch)) {
      if(ch >= '5') 
         return ch-'5'+'0';
      else 
         return ch-'0'+'5';
   } else if(isalpha(ch)) {
      if(isupper(ch)) {
         if(ch >= 'N')
            return ch-'N'+'A';
         else
            return ch-'A'+'N';
      } else {
         if(ch >= 'n')
            return ch-'n'+'a';
         else
            return ch-'a'+'n';
      }
   }
   return ch;
}

char buf[128];

int main(int argc, char *argv[]) {
   int TC, n;
   gets(buf);
   sscanf(buf,"%d",&TC);
   while(TC-- > 0) {
      gets(buf);
      n = strlen(buf);
      for(int i = 0; i < n; ++i)
         putchar(dec(buf[i]));  
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
