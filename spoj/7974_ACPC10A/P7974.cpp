/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ACPC10A C++ "Ad Hoc, Math, Arithmetic progression, Geometric progression" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

const int MAXN = 3;
int a[MAXN], ratio;

bool isArithmetic() {
   int d = a[1]-a[0];
   ratio = d;
   return a[1]==a[0]+d && a[2]==a[0]+2*d;
}

bool isGeometric() {
   if(a[0]==0) return false;
   int d = a[1]/a[0];
   ratio = d;
   return a[1]==a[0]*d && a[2]==a[1]*d;
}

int main(int argc, char *argv[]) {
   while(scanf("%d%d%d",&a[0], &a[1], &a[2])==3) {
      if(a[0]==0 && a[1]==0 && a[2]==0) break;
      if(isArithmetic()) printf("AP %d\n",a[2]+ratio);
      else if(isGeometric()) printf("GP %d\n",a[2]*ratio);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
