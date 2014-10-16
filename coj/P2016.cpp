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

// P for pawns, 
// B for bishops, 
// N for knights, 
// T for towers, 
// Q for queen and K for king
int cost(char ch) {
   if(ch == 'P') return 1;
   else if(ch == 'B' || ch == 'N') return 3;
   else if(ch == 'T') return 5;
   else if(ch == 'Q') return 11;
   return 0;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   
   return 0;
}

