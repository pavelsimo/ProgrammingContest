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

vector<string> dict;

int calc(string &s1, string &s2, int N) {
   for(int i = 0; i < N; ++i) {
      if(s1[i] != s2[i]) 
         return i;
   }
   return N;
}

int main(int argc, char *argv[]) { 
   int N, res;
   string s;
   cin >> N;
   res = N;
   for(int i = 0; i < N; ++i) {
      cin >> s;
      res = s.size();
      dict.push_back(s);
   }
   for(int i = 1; i < N; ++i) {
      string s1 = dict[i - 1];
      string s2 = dict[i];
      res = calc(s1,s2,res);
   }
   cout << res << endl;
   return 0;
}

