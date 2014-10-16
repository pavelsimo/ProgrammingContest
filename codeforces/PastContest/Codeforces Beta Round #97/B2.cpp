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


int main(int argc, char *argv[]) {
   vector<int> va, vb, vc;
   int a, b, c;
   cin >> a >> c;
   while(a || c) {
      va.push_back(a%3); a/=3;
      vc.push_back(c%3); c/=3;
   }
   for(int i = 0; i < sz(va); ++i)
      vb.push_back((vc[i]+3-va[i])%3);
   b = 0;
   for(int i = sz(vb)-1; i >= 0; --i) 
      b = b*3 + vb[i];
   cout << b << endl;
   return 0;
}

