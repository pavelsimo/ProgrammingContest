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

bool is_valid(string &s) {
   if(s.size() >= 2 && s[0] == '0') return false;
   if(s.size() > 7) return false;
   if(s.size() == 7 && atoi(s.c_str()) > 1000000) return false;
   return true;
}

int main(int argc, char *argv[]) { 
   string s;
   cin >> s;
   int N = sz(s);
   int res = -1;
   for(int i = 1; i <= N - 2; ++i) {
      string A = s.substr(0,i);
      for(int j = i + 1; j <= N - 1; ++j) {
         string B = s.substr(i, j - i);   
         string C = s.substr(j);   
         if(!is_valid(A) || !is_valid(B) || !is_valid(C)) continue;
         res = max(res, atoi(A.c_str()) + atoi(B.c_str()) + atoi(C.c_str()));
      }
   }
   cout << res << endl;
   return 0;
}

