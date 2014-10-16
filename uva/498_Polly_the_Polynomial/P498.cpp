/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  498  C++  "Ad Hoc, Math" */
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

typedef long long llong;

int main(int argc, char *argv[]) {  
   string buf;
   llong x;
   while(getline(cin,buf)) {
      istringstream in1(buf);  
      vector<llong> C;
      while(in1 >> x) C.push_back(x);
      getline(cin,buf);
      istringstream in2(buf);  
      for(int k = 0; in2 >> x; ++k) {
         if(k > 0) putchar(' ');
         llong powX = 1LL;
         llong res = 0LL;
         for(int i = sz(C) - 1; i >= 0; --i) {
            res+= C[i] * powX;
            powX*=x;
         }
         printf("%lld",res);
      }
      putchar('\n');
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
