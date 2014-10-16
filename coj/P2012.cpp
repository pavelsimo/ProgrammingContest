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

vector<int> X;

int cost(const string &s) {
   int res = 0;
   for(int i = 0; i < sz(s); ++i) {
      if(s[i] >= 'a' && s[i] <= 'z') 
         res += (s[i] - 'a');
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   string s;
   int best = 0;
   while(cin >> s) {
      int c = cost(s);
      X.push_back(c);
      if(c > best) best = c;
   }
   cout << best << endl;
   for(int i = 0; i < sz(X); ++i) {
      if(X[i] == best)
         cout << i + 1 << endl;
   }      
   return 0;
}

