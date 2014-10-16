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

map<int, int> freq;
int a[100002], sum[100002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int N, M, lo, hi;
   cin >> N >> M;
   sum[0] = 0;
   for(int i = 1; i <= N; ++i) {
      cin >> a[i];
      freq[a[i]]++;
      sum[i] = sum[i-1];
      if(freq[a[i]] == a[i]) sum[i]++;
   }
   while(M-- > 0) {
      cin >> lo >> hi;
      cout << sum[hi] - sum[lo - 1] << endl;
   }
   return 0;
}

