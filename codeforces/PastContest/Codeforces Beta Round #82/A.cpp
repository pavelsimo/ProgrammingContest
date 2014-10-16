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

const string cards = "6789TJQKA";

bool check(string trump, string a, string b) {
   if(a[1]==b[1])
      return cards.find(a[0]) > cards.find(b[0]);
   if(a[1] == trump[0]) return true;
   return false;
}

int main(int argc, char *argv[]) {
   string trump, a, b;
   cin >> trump >> a >> b;
   if(check(trump,a,b)) puts("YES");
   else puts("NO");
   return 0;
}

