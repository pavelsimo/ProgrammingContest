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

int freq[256];

int main(int argc, char *argv[]) {
   string s1, s2;
   getline(cin,s1);
   getline(cin,s2);
   memset(freq, 0, sizeof(freq));
   for(int i = 0; i < sz(s1); ++i) {
      if(isspace(s1[i])) continue;
      freq[(int)s1[i]]++;
   }
   for(int i = 0; i < sz(s2); ++i) {
      if(isspace(s2[i])) continue;
      if(freq[(int)s2[i]] > 0) {
         freq[(int)s2[i]]--;
      } else {
         cout << "NO" << endl;
         return 0;  
      }
   }
   cout << "YES" << endl;
   return 0;
}

