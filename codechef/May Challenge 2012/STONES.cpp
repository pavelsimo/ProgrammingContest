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

int freq[256];

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(0);
   int TC, res;
   string S, J;
   cin >> TC;
   while(TC-- > 0) {
      cin >> J >> S;
      memset(freq, 0, sizeof(freq));
      res = 0;
      for(int i = 0; i < sz(J); ++i) freq[(int)J[i]]++;
      for(int i = 0; i < sz(S); ++i) if(freq[(int)S[i]] > 0) res++;
      printf("%d\n",res);
   }
   return 0;
}
