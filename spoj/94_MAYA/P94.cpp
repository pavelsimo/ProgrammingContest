/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ MAYA C++ "Ad Hoc, Math" */
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
const int MAXN = 15;
llong mayapow[MAXN];
map<string,int> malphabet;

int main(int argc, char *argv[]) {  
   mayapow[0] = 1;
   for(int i = 1; i < MAXN; ++i) {
      mayapow[i] = mayapow[i-1]*20LL;
      if(i==2) mayapow[i]-=40LL;
   }
   malphabet["S"] = 0;
   malphabet["."] = 1;
   malphabet[".."] = 2;
   malphabet["..."] = 3;
   malphabet["...."] = 4;
   malphabet["-"] = 5;
   malphabet[". -"] = 6;
   malphabet[".. -"] = 7;
   malphabet["... -"] = 8;
   malphabet[".... -"] = 9;
   malphabet["- -"] = 10;
   malphabet[". - -"] = 11;
   malphabet[".. - -"] = 12;
   malphabet["... - -"] = 13;
   malphabet[".... - -"] = 14;
   malphabet["- - -"] = 15;
   malphabet[". - - -"] = 16;
   malphabet[".. - - -"] = 17;
   malphabet["... - - -"] = 18;
   malphabet[".... - - -"] = 19;
   
   int N;
   llong res;
   string s;
   while(getline(cin,s)) {
      sscanf(s.c_str(),"%d",&N);
      if(N==0) break;
      res = 0LL;
      for(int i = N-1; i >= 0; --i) {
         getline(cin,s);
         res+=malphabet[s]*mayapow[i];
      }
      printf("%lld\n",res);
      getline(cin,s);
   }  
   return 0;
}
/* @END_OF_SOURCE_CODE */
