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

string s;
map<string, int> m;
vector<string> X;

int main(int argc, char *argv[]) {
   int n;
   char buf[20];
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> s;
      sprintf(buf, "%c%c", s[0], s[sz(s)-1]);

      puts(buf);
   }
   return 0;
}
