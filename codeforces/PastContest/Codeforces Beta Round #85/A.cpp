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

int f(string &s1, string &s2) {
   for(int i = 0; i < sz(s1); ++i) {
      if(tolower(s1[i]) < tolower(s2[i])) return -1;
      if(tolower(s1[i]) > tolower(s2[i])) return 1;
   }
   return 0;
}

int main(int argc, char *argv[]) {
   string s1, s2;
   cin >> s1 >> s2;
   cout << f(s1,s2) << endl;
}

