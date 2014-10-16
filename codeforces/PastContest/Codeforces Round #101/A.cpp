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

int freq[30];

bool solve() {
   for(int i = 0; i < 26; ++i)
      if(freq[i] != 0) return false;
   return true;  
}

int main(int argc, char *argv[]) {   
   memset(freq,0,sizeof(freq));
   string a, b, c;
   cin >> a >> b >> c;
   for(int i = 0; i < sz(a); ++i)
      freq[a[i]-'A']++;
   for(int i = 0; i < sz(b); ++i)
      freq[b[i]-'A']++;
   for(int i = 0; i < sz(c); ++i)
      freq[c[i]-'A']--;
   if(solve()) puts("YES");
   else puts("NO");
   return 0;
}

