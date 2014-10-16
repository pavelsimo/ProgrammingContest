/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  256  C++  "Brute Force" */
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

int lo[] = {0,0,0,0,3,0,8,0,13};
int hi[] = {0,0,3,0,8,0,13,0,22};

char res[30][10] = {"00","01","81",
   "0000","0001","2025","3025","9801",
   "000000","000001","088209","494209","998001",
   "00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};

int main(int argc, char *argv[]) {
   int N;
   while(1==scanf("%d",&N)) {
      for(int i = lo[N]; i < hi[N]; ++i)
         puts(res[i]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
