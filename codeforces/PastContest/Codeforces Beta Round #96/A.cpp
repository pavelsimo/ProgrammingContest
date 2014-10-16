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

bool check(string &s) {
   for(int i = 0; i < sz(s); ++i)
      if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9') 
         return true;
   return false;
}

int main(int argc, char *argv[]) {   
   string s;
   cin >> s;
   if(check(s)) puts("YES");
   else puts("NO");
   return 0;
}
