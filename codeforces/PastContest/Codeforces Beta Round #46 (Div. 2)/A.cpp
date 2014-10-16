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
   ch = toupper(ch);
   return ch == 'A' ||  ch == 'E' || 
      ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y';
}

int main(int argc, char *argv[]) {
   string s;
   getline(cin,s);
   bool q_mark = false;
   for(int i = sz(s) - 1; i >= 0; --i) {
      if(s[i] == '?') q_mark = true;
      if(q_mark && isalpha(s[i])) {
         cout << (is_vocal(s[i]) ? "YES": "NO") << endl;
         break;
      }
   }
   return 0;
}

 
