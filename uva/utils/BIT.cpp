#include <algorithm>
#include <cassert>
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

const int MAXN = 1000002;
int tree[MAXN];

int read(int idx) {
   int res = 0;
   while(idx > 0) {
      res+=tree[idx];
      idx-=(idx & -idx);
   }
   return res;
}

void update(int idx, int val) {
   while(idx < MAXN) {
      tree[idx]+=val;  
      idx +=(idx & -idx);
   }
}

int main() {
   memset(tree,0,sizeof(tree));
   
   return 0;
}
