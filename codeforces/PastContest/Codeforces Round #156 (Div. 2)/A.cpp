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

int cnt[3];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, a;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> a;
      cnt[i%3] += a;
   }
   if(cnt[0] > cnt[1] && cnt[0] > cnt[2]) cout << "chest" << endl;
   else if(cnt[1] > cnt[0] && cnt[1] > cnt[2]) cout << "biceps" << endl;
   else cout << "back" << endl;
   return 0;
}
