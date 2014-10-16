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
   string s1, s2;
   cin >> s1 >> s2;
   sort(s2.rbegin(),s2.rend());
   int j = 0;
   for(int i = 0; i < sz(s1); ++i) {
      if(j < sz(s2) && s2[j] > s1[i]) {
         s1[i] = s2[j];
         j++;
      }
   }
   cout << s1 << endl;
   return 0;
}

