/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ FORMALLA C++ "Ad Hoc" */
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


int main(int argc, char *argv[]) {
   string s;
   int TC, N, a[4], X, Y;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,s);
      sscanf(s.c_str(),"%d",&N);
      a[1] = 1; a[2] = a[3] = 0;
      for(int i = 0; i < N; ++i) {
         getline(cin,s);
         sscanf(s.c_str(),"%d-%d",&X,&Y);
         swap(a[X],a[Y]);
      }
      for(int i = 1; i <= 3; ++i) {
         if(a[i]) {
            printf("%d\n",i);
            break;
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
