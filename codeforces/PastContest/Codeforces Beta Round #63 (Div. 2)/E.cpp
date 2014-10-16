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

map<int,int> freq;
set<int> S;
int a[100002];

int main(int argc, char *argv[]) {
   int n, k, lo, hi;
   cin >> n >> k;
   for(int i = 0; i < n; ++i)
      cin >> a[i];
   for(int i = 0; i < k; ++i) {
      freq[a[i]]++;;
      if(freq[a[i]] == 1) S.insert(a[i]);
      else if(freq[a[i]] >= 2) S.erase(a[i]);
   }   
   if(sz(S)) cout << *S.rbegin() << endl;
   else cout << "Nothing" << endl;
   lo = 0, hi = k;
   while(hi < n) {
      --freq[a[lo]];
      ++freq[a[hi]];

      if(freq[a[lo]] == 1) S.insert(a[lo]);
      else if(freq[a[lo]] == 0) S.erase(a[lo]);
      
      if(freq[a[hi]] == 1) S.insert(a[hi]);
      else if(freq[a[hi]] >= 2) S.erase(a[hi]);

      if(sz(S) == 0) cout << "Nothing" << endl;
      else cout << *S.rbegin() << endl;
      lo++;
      hi++;
   }
   return 0;
}

