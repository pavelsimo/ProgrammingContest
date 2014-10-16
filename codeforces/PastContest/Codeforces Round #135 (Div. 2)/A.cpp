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

int freq[26];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   string s, p;
   int k;
   cin >> k >> s;
   if(k == 1) {
      cout << s << endl;
      return 0;      
   }
   for(int i = 0; i < sz(s); ++i) 
      freq[s[i]-'a']++;
   for(int i = 0; i < 26; ++i) {
      if(!freq[i]) continue;
      if(freq[i] < k || freq[i] % k != 0) {
         cout << -1 << endl;
         return 0;
      }
   }
   p = "";
   for(int i = 0; i < 26; ++i) {
      if(!freq[i]) continue;
      p += string(freq[i]/k, 'a' + i);
   }
   for(int i = 0; i < k; ++i) cout << p;
   cout << endl;
   return 0;
}

