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

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string q;
   int TC;
   getline(cin, q);
   sscanf(q.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin, q);
      set<char> S;
      for(int i = 0; i < sz(q); ++i)
         S.insert(tolower(q[i]));
      char ch;
      for(ch = 'a'; ch <= 'z'; ++ch) {
         if(S.count(ch) == 0) {
            cout << ch << endl;
            break;
         }
      }
      if(ch > 'z') cout << '~' << endl;
   }
   return 0;
}
