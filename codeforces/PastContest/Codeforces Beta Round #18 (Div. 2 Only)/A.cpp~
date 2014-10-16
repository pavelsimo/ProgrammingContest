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
   string flag[102];
   int n, m;
   cin >> n >> m;
   for(int i = 0; i < n; ++i)
      cin >> flag[i];
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
         if(i - 1 >= 0 && flag[i-1][j] == flag[i][j]) {
            cout << "NO" << endl;
            return 0;            
         }
         if(i + 1 < n && flag[i+1][j] == flag[i][j]) {
            cout << "NO" << endl;
            return 0;
         }
         if(j - 1 >= 0 && flag[i][j-1] != flag[i][j]) {
            cout << "NO" << endl;
            return 0;
         }          
      }      
   }
   cout << "YES" << endl;
   return 0;
}

