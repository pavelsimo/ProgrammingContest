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

const int MAXN = 1000;
int X[MAXN], Y[MAXN];

int main(int argc, char *argv[]) { 
   int N, res = 0;
   cin >> N;
   for(int i = 0; i < N; ++i)
      cin >> X[i] >> Y[i];
   for(int i = 0; i < N; ++i) {
      bool upper, lower, right, left;
      upper = lower = right = left = false;
      for(int j = 0; j < N; ++j) {
         if(i == j) continue;         
         if(X[i] == X[j] && Y[i] < Y[j]) upper = true;
         if(X[i] == X[j] && Y[i] > Y[j]) lower = true;
         if(Y[i] == Y[j] && X[i] > X[j]) left = true;
         if(Y[i] == Y[j] && X[i] < X[j]) right = true;
      }
      if(upper && lower && left && right) res++;
   }
   cout << res << endl;
   return 0;
}

