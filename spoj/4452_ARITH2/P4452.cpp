/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ARITH2 C++ "Ad Hoc, Simple Math" */
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

typedef long long llong;

int main(int argc, char *argv[]) {
   int TC; 
   char op;
   llong res, cur;
   string s, buf;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);    
   while(TC-- > 0) {
      getline(cin,buf);
      getline(cin,buf);
      istringstream in(buf);
      res=0LL;
      op='+';
      for(int i = 0; in >> s; ++i) {
         if(s[0]=='=') break;
         if(s[0]=='+' || s[0]=='*' || s[0]=='/' || s[0]=='-') {
            op = s[0];
         } else {
            sscanf(s.c_str(),"%lld",&cur);
            if(op=='+') res+=cur;
            else if(op=='*') res*=cur;
            else if(op=='/') res/=cur;          
            else if(op=='-') res-=cur;
         }
      }
      printf("%lld\n",res);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

