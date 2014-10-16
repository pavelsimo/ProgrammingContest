/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12019  C++  "Ad Hoc, Dates" */
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

const char *day_of_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const int month_first_day[] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

int main(int argc, char *argv[]) {
   int TC, M, D;
   scanf("%d",&TC);
   while(TC-- > 0) {
      scanf("%d%d",&M,&D);
      int d = month_first_day[M - 1];
      d = (d + D - 1) % 7;
      puts(day_of_week[d]);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
