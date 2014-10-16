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

bool cmp(const string &a, const string &b) {
   if(sz(a) != sz(b)) return sz(a) > sz(b);
   for(int i = 0; i < sz(a); ++i)
      if(a[i] < b[i])
         return false;
   return true;
}

string solve(const string &S) {
   string res = "", t = "";
   for(int i = 0; i < sz(S); ++i) {
      if(isdigit(S[i])) {
         if(!(sz(t) == 0 && S[i] == '0'))
            t += S[i];
      } else {
         t = "";
      }
      if(cmp(t, res)) res = t;
   }
   return res;
}


int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string S, res;
   while(cin >> S) {
      res = solve(S);
      for(int i = 0; i < sz(S); ++i) {
         if(S[i] >= 'A' && S[i] <= 'Z') {
            char temp = S[i];
            S[i] = '9';
            string t = solve(S);
            if(cmp(t, res)) res = t;
            S[i] = temp;
         }
      }
      if(sz(res) == 0) res = "0";
      cout << res << endl;
   }
   return 0;
}

