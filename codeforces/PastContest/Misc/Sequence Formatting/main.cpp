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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())


int main() {
   string s, t, res;
   getline(cin,s);
   for(int i = 0; i < sz(s); ++i) {
      if(isspace(s[i])) continue; 
      t+=s[i];
   }
   for(int i = 0; i < sz(t); ++i) {
      if(i-1 >= 0 && t[i-1]==',')
         res+=' ';
      if(i-1 >= 0 && t[i]=='.' && (isdigit(t[i-1])))
         res+=' ';
      res+=t[i];
   }
   int cnt = 0;
   for(int i = 0; i < sz(res); ++i) {
      if(res[i]=='.') cnt++;
      else cnt = 0;
      if(i-1 >= 0 && cnt==4 && res[i-1]=='.') 
         putchar(' ');
      putchar(res[i]);
   }
   cout << endl;
   return 0;
}
