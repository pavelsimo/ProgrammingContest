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

string a[102], b[102];

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   int na, ma, nb, mb, res = 0, bx, by;
   cin >> na >> ma;
   for(int i = 0; i < na; ++i)
      cin >> a[i];
   cin >> nb >> mb;
   for(int i = 0; i < nb; ++i)
      cin >> b[i];   
   bx = by = 0;
   for(int x = -52; x < nb; ++x) {
      for(int y = -52; y < mb; ++y) {
         int sum = 0;
         for(int i = 0; i < na; ++i) {
            for(int j = 0; j < ma; ++j) {
               if(i + x >= 0 && j + y >= 0 && i + x < nb && j + y < mb)
                  sum += (a[i][j] - '0') * (b[i+x][j+y] - '0');
            }
         }
         if(sum > res) {
            res = sum;
            bx = x;
            by = y;
         }
      }
   }
   cout << bx << " " << by << endl;
   return 0;
}

