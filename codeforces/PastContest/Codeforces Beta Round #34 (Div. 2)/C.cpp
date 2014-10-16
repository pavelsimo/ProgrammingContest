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

typedef long long llong;

int main(int argc, char *argv[]) {
   string s, token;
   set<int> X;
   cin >> s;
   istringstream in(s);
   while(getline(in,token,','))
      X.insert(atoi(token.c_str()));
   vector<int> a(all(X));
   for(int i = 0; i < sz(a); ++i) {
      if(i > 0) cout << ',';
      cout << a[i];
      int j;
      for(j = i + 1; j < sz(a); ++j)
         if(a[j-1] + 1 != a[j]) break;
      if(a[j-1] > a[i]) cout << '-' << a[j-1];
      i = j - 1;
   }
   cout << endl;
   return 0;
}

