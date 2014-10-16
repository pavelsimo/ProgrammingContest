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

vector<string> A;

string song[] = {"Happy","birthday","to","you",
                 "Happy","birthday","to","you",
                 "Happy","birthday","to","Rujia",
                 "Happy","birthday","to","you"};

int f(int x) {
   if(x <= 16) return 16;
   if(x <= 32) return 32;
   if(x <= 48) return 48;
   if(x <= 48) return 48;
   if(x <= 64) return 64;
   if(x <= 80) return 80;
   if(x <= 96) return 96;
   return 112;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string name;
   int n, m;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> name;
      A.push_back(name);
   }
   m = f(n);
   for(int i = 0, j = 0; i < m; i++, j = (j + 1) % 16)
      cout << A[i % sz(A)] << ": " << song[j] << '\n';
   return 0;
}
