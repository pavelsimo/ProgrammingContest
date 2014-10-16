/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11936  C++  "Ad Hoc, Math" */
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
   int TC, a[3];
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d%d",&a[0],&a[1],&a[2]);
      sort(a,a+3);
      if(a[0] + a[1] > a[2]) puts("OK");
      else puts("Wrong!!");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
