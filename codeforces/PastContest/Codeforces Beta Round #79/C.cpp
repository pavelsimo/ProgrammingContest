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

const int INF = 0x3f3f3f3f;
int freq[26];
int freq2[26];

int get_min() {
   int res = INF;
   int k = INF;
   for(int i = 0; i < 26; ++i) {
      if(freq[i]!=0) 
         k = min(k,freq[i]);
   }
   for(int i = 0; i < 26; ++i)
      if(freq[i]==k) 
         return i;
   return res;
}

int main(int argc, char *argv[]) {
   memset(freq,0,sizeof(freq));
   int k, m = 0;   
   string s;
   cin >> s >> k;
   for(int i = 0; i < sz(s); ++i) {
      freq[s[i]-'a']++;
      freq2[s[i]-'a']++;
   }
   for(int i = 0; i < k; ++i) {
      int j = get_min();
      if(j==INF) break;
      freq[j]--;
   }
   string res = "";
   for(int i = 0; i < 26; ++i) {
      if(freq[i] > 0) {
         m++;
         res+=string(freq[i],char('a'+i));
      }
   }
   cout << m << endl;
   cout << res << endl;
   return 0;
}

