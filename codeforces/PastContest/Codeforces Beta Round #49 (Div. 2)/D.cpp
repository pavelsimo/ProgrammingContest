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


int a[302], b[302];
vector<pair<int,int> > S;

int main(int argc, char *argv[]) {
   int n;
   cin >> n;
   for(int i = 0; i < n; ++i) cin >> a[i];
   for(int i = 0; i < n; ++i) cin >> b[i];   
   for(int i = 0; i < n; ++i) {
      if(a[i] != b[i]) {
         int j;
         for(j = i + 1; j < n; ++j)
            if(b[j] == a[i]) break;
         int hi = j, lo = j - 1;
         while(lo >= i) {
            swap(b[lo],b[hi]);
            S.push_back(make_pair(lo+1,hi+1));
            lo--;
            hi--;
         }
      }
   }
   cout << sz(S) << endl;
   for(int i = 0; i < sz(S); ++i)
      cout << S[i].first << ' ' << S[i].second << '\n';
   return 0;
}

