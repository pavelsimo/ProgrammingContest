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

int a[100002], freq[100002];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int N, K;
   cin >> N >> K;
   for(int i = 0; i < N; ++i) 
      cin >> a[i];
   for(int i = 0, k = 0; i < N; ++i) {
      freq[a[i]]++;
      if(freq[a[i]] == 1) k++;
      if(k == K) {
         int j;
         for(j = 0; j <= i; ++j) {
            if(freq[a[j]] - 1 == 0) break;
            freq[a[j]]--;
         }
         cout << j + 1 << " " << i + 1 << endl;
         return 0;
      }
   }
   cout << -1 << " " << -1 << endl;
   return 0;
}

