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

const string p = "hello";

int main(int argc, char *argv[]) {
   string s;
   cin >> s;
   int i, j;
   for(i = 0, j = 0; i < sz(s); ++i) {
      if(s[i] == p[j]) j++;
      if(j == sz(p)) break;
   }
   if(j == sz(p)) cout << "YES" << endl;
   else cout << "NO" << endl;
   return 0;
}

 
