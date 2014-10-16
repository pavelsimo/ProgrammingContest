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
   string a, b;
   cin >> a >> b;
   int cnt4 = 0, cnt7 = 0;
   for(int i = 0; i < sz(a); ++i) {
      if(a[i] == '4') {
         if(a[i]!=b[i]) cnt4++;   
      } else {
         if(a[i]!=b[i]) cnt7++; 
      }
   } 
   cout << max(cnt4,cnt7) << endl;
   return 0;
}

