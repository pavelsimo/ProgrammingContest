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

/*
a   y
b   h
c   e
d   s
e   o
f   c
g   v
h   x
i   d
j   u
k   i
l   g
m   l
n   b
o   k
p   r
q   z
r   t
s   n
t   w
u   j
v   p
w   f
x   m
y   a
z   q
*/
const string alphabet = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int TC;
   string s, res;
   getline(cin, s);
   sscanf(s.c_str(),"%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      getline(cin, s);
      res = s;
      for(int i = 0; i < sz(s); ++i) {
         if(isspace(s[i])) continue;
         res[i] = alphabet[s[i] - 'a'];
      }
      printf("Case #%d: %s\n",tc, res.c_str());
   }
   return 0;
}

