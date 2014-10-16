/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12149  C++  "Simple Math" */
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

int N;
const int MAXN = 102;
int A[MAXN];

int main(int argc, char *argv[]) {
   A[0]=0;
   A[1]=1;
   for(int i = 2; i <= 100; ++i)
         A[i]=A[i-1]+i*i;
   while(1==scanf("%d",&N)) {
      if(N==0)break;
      printf("%d\n",A[N]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
