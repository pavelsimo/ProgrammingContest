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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

void replace_all(string &s, const string &from, const string &to, size_t pos = 0) {
   while((pos = s.find(from, pos)) != string::npos) {
      s.replace(pos, from.length(), to);
      pos += to.length();
   }
}

void find_rpl(string &s, const string &from, const string &to, size_t pos = 0) {
   if((pos = s.find(from, pos)) != string::npos) {
      s.replace(pos, from.length(), to);
      pos += to.length();
   }
}

int main(int argc, char *argv[]) {
   string s = "pavel y brenda son lala";
   replace_all(s, "lala", "novios");
   cout << s << endl;
   find_rpl(s, "pavel", "Pavel");
   find_rpl(s, "brenda", "Brenda");
   cout << s << endl;
   return 0;
}
// END CUT HERE
