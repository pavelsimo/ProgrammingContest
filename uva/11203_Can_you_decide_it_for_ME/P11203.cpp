/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11203  C++  "Ad Hoc, Frequency" */
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

int freq[256];

int main(int argc, char *argv[]) {
   int TC;
   string buf;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   while(TC-- > 0) {
      memset(freq,0,sizeof(freq));
      getline(cin,buf);
      bool ok = true;
      for(int i = 0; i < sz(buf); ++i) {
         if(buf[i]=='M' || buf[i]=='E' || buf[i]=='?') {
            freq[int(buf[i])]++; 
         } else {
            ok = false;
            break;
         }
      }
      if(ok && freq['M']==1 && freq['E']==1) {
         size_t p1 = buf.find('M');
         size_t p2 = buf.find('E');
         string x = buf.substr(0,p1);
         string y = buf.substr(p1+1,p2-p1-1);
         string z = buf.substr(p2+1);
         if(sz(x) >= 1 && sz(y) >= 1 && sz(z) >= 2 && sz(x)+sz(y)==sz(z))
            puts("theorem");   
         else
            puts("no-theorem");  
      } else {
         puts("no-theorem");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
