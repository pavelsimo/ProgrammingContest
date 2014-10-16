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

string r1, r2;
int freq[26];

bool is_granama() {
   memset(freq, 0, sizeof(freq));
   if(sz(r1) != sz(r2)) return false;
   for(int i = 0; i < sz(r1); ++i) freq[r1[i]-'a']++;
   for(int i = 0; i < sz(r2); ++i) freq[r2[i]-'a']--;   
   for(int i = 0; i < 26; ++i)
      if(freq[i] != 0) 
         return false;
   return true;
}

bool is_chef_granama() {
   set<char> S1(all(r1));
   set<char> S2(all(r2));
   return S1 == S2;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   cin >> TC;
   while(TC-- > 0) {
      cin >> r1 >> r2;
      cout << (is_chef_granama() == is_granama() ? "YES" : "NO") << endl;
   }
   return 0;
}

