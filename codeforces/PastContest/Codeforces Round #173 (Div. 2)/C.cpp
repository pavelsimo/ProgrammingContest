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

int freqA[2], freqB[2];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string A, B;
   cin >> A >> B;
   if(sz(A) != sz(B)) {
      cout << "NO" << endl;
      return 0;
   }
   for(int i = 0; i < sz(A); ++i)
      freqA[A[i]-'0']++, freqB[B[i]-'0']++;
   
   if(freqA[0] == sz(A) && freqB[0] == sz(B)) {
      cout << "YES" << endl;
      return 0;
   }
   if((freqB[0] == sz(B) && freqA[1] >= 1)
   || (freqA[0] == sz(A) && freqB[1] >= 1)) {
      cout << "NO" << endl;
      return 0;
   }
   cout << "YES" << endl;
   return 0;
}
