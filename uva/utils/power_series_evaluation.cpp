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

// O(log(n)) - pow
int m_pow(int x, int n) {
   if(n==0) return 1;
   if(n & 1) {
      return m_pow(x,n-1)*x;
   } else {
      int t;
      t = m_pow(x,n >> 1);
      return t*t;
   }
}

/*
http://zobayer.blogspot.com/2009/12/power-series-evaluation.html
We have, 1 + x + x2 + x3 + x4 + x5
⇒ (1 + x + x2) + x3(1 + x + x2)
⇒ (1 + x + x2)(1 + x3)
*/
int evaluate1(int x, int n) {
   if(n==0) return 0;
   if(n==1) return 1;
   int ret = 0;
   if(n & 1)
      ret = ret + m_pow(x, n-1);
   n = n >> 1;
   return ret + evaluate1(x, n)*(1 + m_pow(x, n));
}

int evaluate2(int x, int n) {
   if(n==0) return 0;
   if(n==1) return 1;
   int ret = 0;
   if(n & 1)
      ret = ret + m_pow(x, n-1);
   n = n >> 1;
   int t = evaluate2(x, n);
   return ret + t + t*m_pow(x, n);
}

int main() {
   // 2^0 + 2^1 + 2^2 + 2^3 = 15
   cout << evaluate2(2,4) << endl;
   return 0;
}
