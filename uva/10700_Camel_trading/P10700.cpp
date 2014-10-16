/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10700  C++  "DP, Dynamic Programming" */
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
map<string,llong> memo;
const llong INF = 191920000000000000LL;

llong dmax(string s) {
   if(s.find_first_of("+*")==string::npos)
      return llong(atoi(s.c_str()));
   llong res = 0;
   if(memo.count(s)!=0) 
      return memo[s];
   for(int i = 0; i < sz(s); ++i) {
      if(s[i]=='+') res = max(res, dmax(s.substr(0,i)) + dmax(s.substr(i+1)));
      if(s[i]=='*') res = max(res, dmax(s.substr(0,i)) * dmax(s.substr(i+1)));
   }
   return memo[s] = res;
}

llong dmin(string s) {
   if(s.find_first_of("+*")==string::npos)
      return llong(atoi(s.c_str()));
   llong res = INF;
   if(memo.count(s)!=0) 
      return memo[s];
   for(int i = 0; i < sz(s); ++i) {
      if(s[i]=='+') res = min(res, dmin(s.substr(0,i)) + dmin(s.substr(i+1)));
      if(s[i]=='*') res = min(res, dmin(s.substr(0,i)) * dmin(s.substr(i+1)));
   }
   return memo[s] = res;
}

int main(int argc, char *argv[]) {
   string s;
   int TC;
   llong lo, hi;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,s);   
      memo.clear(); lo = dmax(s);
      memo.clear(); hi = dmin(s);
      printf("The maximum and minimum are %lld and %lld.\n",lo,hi);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
