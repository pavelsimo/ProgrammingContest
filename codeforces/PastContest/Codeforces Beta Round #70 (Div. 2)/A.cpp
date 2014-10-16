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

typedef long long llong;

bool is_vocal(char ch) {
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int count(string &s) {
   int res = 0;
   for(int i = 0; i < sz(s); ++i)
      if(is_vocal(s[i])) res++;
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   string a, b, c;
   getline(cin,a);
   getline(cin,b);
   getline(cin,c);
   if(count(a) == 5 && count(b) == 7 && count(c) == 5)
      cout << "YES" << '\n';
   else 
      cout << "NO" << '\n';
   return 0;
}

