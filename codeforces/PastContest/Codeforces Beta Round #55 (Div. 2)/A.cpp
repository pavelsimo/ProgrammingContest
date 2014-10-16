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
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


int main(int argc, char *argv[]) {
   string s;
   int cntL = 0, cntU = 0;
   cin >> s;
   for(int i = 0; i < sz(s); ++i) {
      if(isupper(s[i])) cntU++;
      else cntL++;
   }
   if(cntL >= cntU) {
      for(int i = 0; i < sz(s); ++i)
         s[i] = tolower(s[i]);
   } else {
      for(int i = 0; i < sz(s); ++i)
         s[i] = toupper(s[i]);
   }
   cout << s << endl;
   return 0;
}

 
