/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11078  C++  "Math, Pascal Triangle" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

string S[] = {
"negative", "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", "thousand", "million"};

int P[] = {1,10,100,1000,10000,100000,1000000,10000000};

int V[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
      17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000};

int main(int argc, char *argv[]) {
   string s, token;
   while(getline(cin, s)) {
      istringstream in(s);
      int res = 0;
      bool neg = false;
      while(in >> token) {
	 size_t pos = find(S, S + 32, token) - S;

      }
      if(neg) res *= -1;
      cout << res << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
