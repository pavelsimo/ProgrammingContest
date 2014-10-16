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

int freq[12];
string S;
bool del[102];

void solve(int s, int e) {
   memset(freq, 0, sizeof(freq));
   memset(del, false, sizeof(del));
   string X = "";
   for(int i = s; i <= e; ++i) X += S[i];
   int p = 0, dir = 1;
   int prev = -1;
   while(p >= 0 && p < sz(X)) {
      if(del[p]) {
         p+=dir;
         continue;
      }
      if(X[p] == '0') {
         freq[0]++;
         del[p] = true;
      } else if(isdigit(X[p])) {
         freq[X[p] - '0']++;
         X[p]--;
      } else if(X[p] == '>') {
         dir = +1;
         if(X[prev] == '<' || X[prev] == '>') del[prev] = true;
      } else if(X[p] == '<') {
         dir = -1;
         if(X[prev] == '<' || X[prev] == '>') del[prev] = true;
      }
      prev = p;
      p += dir;
   }
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n, q, lo, hi;
   cin >> n >> q >> S;
   while(q-- > 0) {
      cin >> lo >> hi;
      --lo, --hi;
      solve(lo, hi);
      for(int i = 0; i <= 9; ++i) {
         if(i > 0) cout << ' ';
         cout << freq[i];
      }
      cout << endl;
   }
   return 0;
}

