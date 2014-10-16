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
   string code, s;
   getline(cin,code);
   map<string,int> m;
   for(int i = 0; i < 10; ++i) {
      getline(cin,s);  
      m[s] = i;
   }
   for(int i = 0; i < sz(code); i+=10) {
      string s = code;
      s = s.substr(i,10);
      printf("%d",m[s]);
   }
   putchar('\n');
   return 0;
}

