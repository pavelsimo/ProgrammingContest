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

int D[10];
int main(int argc, char *argv[]) {
   memset(D,0,sizeof(D));
   string s;
   cin >> s;
   for(int i = 0; i < sz(s); ++i) D[s[i]-'0']++;
   if(D[7] == 0 && D[4] == 0) puts("-1");
   else if(D[7] > D[4]) puts("7");
   else puts("4");
   return 0;
}

