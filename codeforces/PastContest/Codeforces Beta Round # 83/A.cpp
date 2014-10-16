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
   int H, M;
   char buf[16];
   scanf("%d:%d",&H,&M);
   while(true) {
      M++;
      if(M==60) H++, M = 0;
      if(H==24) H = 0;
      if(H/10 == M%10 && H%10 == M/10) { 
         sprintf(buf,"%02d:%02d",H,M);
         puts(buf);
         break;
      }
   }
   return 0;
}

