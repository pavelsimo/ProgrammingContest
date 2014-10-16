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

map<int,int> m_id;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int n, m, x;
   long long pa, pb;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> x;
      m_id[x] = i;
   }
   cin >> m;
   pa = pb = 0LL;
   while(m-- > 0) {
      cin >> x;
      int ind = m_id[x];
      pa += (ind + 1LL);
      pb += n - ind;
   }
   cout << pa << " " << pb << endl;
   return 0;
}

