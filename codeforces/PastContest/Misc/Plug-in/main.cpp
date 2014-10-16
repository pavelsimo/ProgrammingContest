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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())


int main() {
   string s;
   cin >> s;
   stack<char> st1, st2, out;
   for(int i = 0; i < sz(s); ++i) {
      if(!st1.empty() && st1.top()==s[i]) {
         st1.pop();
      } else if(!st1.empty() && st1.top()!=s[i]) {
         st2.push(st1.top());
         st1.pop();
      } else {
         if(!st2.empty()) {
            if(st2.top()==s[i]) st2.pop();
            else st2.push(s[i]);
         } else {
            st2.push(s[i]);
         }
      }
   }
   while(!st2.empty()) {
      out.push(st2.top());
      st2.pop();
   }
   while(!out.empty()) {
      putchar(out.top());
      out.pop();
   }
   putchar('\n');
   return 0;
}
