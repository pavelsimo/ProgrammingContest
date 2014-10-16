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

typedef long long llong;

const llong MOD = 1000000007LL;
int freq[26];
int A[200];

int main(int argc, char *argv[]) {
   vector<string> dict;
   llong res = 1LL;
   string word;
   int N, M;
   cin >> N >> M;
   for(int i = 0; i < N; ++i) {
      cin >> word;
      dict.push_back(word);
   }
   for(int j = 0; j < M; ++j) {
      memset(freq,0,sizeof(freq));
      for(int i = 0; i < N; ++i) {
         if(!freq[dict[i][j]-'A']) {
            A[j]++;
            freq[dict[i][j]-'A']++;
         }
      }
   }
   for(int j = 0; j < M; ++j)
      res = (res * llong(A[j])) % MOD;
   cout << res << endl;
   return 0;
}

