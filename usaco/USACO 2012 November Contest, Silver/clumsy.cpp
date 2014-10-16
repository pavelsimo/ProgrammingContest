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

stack<char> S;
int P[2];

int main() {
    freopen("clumsy.in", "r", stdin);
    freopen("clumsy.out", "w", stdout);
    string s;
    P[0] = P[1] = 0;
    cin >> s;
    int res = 0;
    for(int i = 0; i < sz(s); ++i) {
       if(S.empty()) {
          S.push(s[i]);
          continue;
       }
       if(S.top() == '(' && s[i] == ')') S.pop();
       else S.push(s[i]);
    }
    while(!S.empty()) {
       char ch = S.top();
       S.pop();
       if(ch == '(') P[0]++;
       else P[1]++;
    }
    res  = P[0]/2 + P[1]/2;
    res += P[0]%2 + P[1]%2;
    cout << res << endl;
    return 0;
}
