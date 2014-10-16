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

string S;
int seen[102];

void go(int i, int j) {
   if(S[i] == 'R' && S[j] == 'L') 
      cout << j + 1 << ' ' << i + 1 << endl;
   else 
      cout << i + 1 << ' ' << j + 1 << endl;   
}

int main(int argc, char *argv[]) { 
   memset(seen, false, sizeof(seen));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
   int n;
   cin >> n >> S;
   int k = n/2;
   for(int i = 0; i < n; ++i) {
      if(seen[i]) continue;
      int j;
      for(j = i + k; j < n; ++j) 
         if(!seen[j]) break;
      go(i, j);
      seen[i] = seen[j] = true;
   }
   return 0;
}

