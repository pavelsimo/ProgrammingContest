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

bool play(char a, char b) {
   if(a == 'R' && b == 'S') return 1;
   if(a == 'S' && b == 'P') return 1;
   if(a == 'P' && b == 'R') return 1;
   return 0;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   string a, b;
   int cntA, cntB, N, j, k, i;
   cin >> N >> a >> b;
   cntA = cntB = 0;
   i = j = k = 0;
   for(i = 0; i < N; ++i) {
      if(j >= sz(a)) j = 0;
      if(k >= sz(b)) k = 0;
      if(i > 0 && j == 0 && k == 0) break;
      char p1 = a[j++];
      char p2 = b[k++];
      if(p1 == p2) continue;
      if(play(p1,p2)) cntB++;
      else cntA++;
   }
   int X = N - i;
   cntA = cntA + cntA*(X/i);
   cntB = cntB + cntB*(X/i);
   int R = X % i;
   i = j = k = 0;
   for(i = 0; i < R; ++i) {
      if(j >= sz(a)) j = 0;
      if(k >= sz(b)) k = 0;
      char p1 = a[j++];
      char p2 = b[k++];
      if(p1 == p2) continue;
      if(play(p1,p2)) cntB++;
      else cntA++;
   }
   cout << cntA << ' ' << cntB << endl;
   return 0;
}

