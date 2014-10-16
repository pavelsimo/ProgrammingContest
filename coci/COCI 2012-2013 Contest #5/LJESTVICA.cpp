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

typedef long long llong;

bool is_aminor(char ch) {
   return ch == 'A' || ch == 'D' || ch == 'E';
}

bool is_cmajor(char ch) {
   return ch == 'C' || ch == 'F' || ch == 'G';
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int a_mi, c_ma;
   string s, note;
   cin >> s;
   istringstream in(s);
   a_mi = c_ma = 0;
   while(getline(in, note, '|')) {
      if(is_aminor(note[0])) a_mi++;
      if(is_cmajor(note[0])) c_ma++;
   }
   if(a_mi > c_ma) cout << "A-mol" << endl;
   else if(a_mi < c_ma) cout << "C-dur" << endl;
   else cout << (is_aminor(s[sz(s)-1]) ? "A-mol": "C-dur") << endl;
   return 0;
}

