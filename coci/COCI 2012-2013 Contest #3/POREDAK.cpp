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

int A[3002];
map<string, int> m_id;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   string s;
   cin >> N;
   for(int i = 0; i < N; ++i) {
      cin >> s;
      m_id[s] = i;
   }
   for(int i = 0; i < N; ++i) {
      cin >> s;
      A[i] = m_id[s];
   }
   int pts = 0;
   for(int i = 0; i < N; ++i) {
      for(int j = i + 1; j < N; ++j) {
         if(A[i] < A[j]) pts++;
      }
   }
   cout << pts << "/" << N * (N-1) / 2 << endl;
   return 0;
}

