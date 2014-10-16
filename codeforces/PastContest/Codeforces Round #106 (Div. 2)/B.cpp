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

const int MAXN = 60;

int tonum(char ch) {
   if(isdigit(ch)) 
      return ch - '0';
   return ch - 'A' + 10;
}

int todecimal(string s, int base) {
   int res = 0;
   for(int i = 0; i < sz(s); ++i)
      res = res*base + tonum(s[i]);
   return res;
}

int main(int argc, char *argv[]) {
   string s, h, m;
   cin >> s;
   istringstream in(s);
   getline(in, h, ':');
   getline(in, m, ':');
   int base = 0;
   for(int i = 0; i < sz(h); ++i) base = max(base, tonum(h[i]));
   for(int i = 0; i < sz(m); ++i) base = max(base, tonum(m[i]));
   int i, phh = -1, pmm = -1;
   bool inf = false;
   for(i = base + 1; i <= 60; ++i) {
      int hh = todecimal(h,i);
      int mm = todecimal(m,i);
      if(hh == phh && mm == pmm) inf = true;
      if(hh > 23 || mm > 59) break;
      phh = hh;
      pmm = mm;
   }
   if(inf) {
      puts("-1");
   } else if(i == base + 1) {
      puts("0");
   } else {
      for(int j = base + 1; j < i; ++j) {
         if(j > base + 1) putchar(' ');
         printf("%d",j);
      }
      putchar('\n');
   }
   return 0;
}

