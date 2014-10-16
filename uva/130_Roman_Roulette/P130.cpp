/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  440  C++  "Ad Hoc, Josephus Problem" */
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


list<int>::iterator next(list<int> &A, list<int>::iterator it, int n) {
   list<int>::iterator res = (it == A.end()) ? A.begin() : it;
   if(sz(A) == 1) 
      return res;
   if(n > 0) {
      for(int i = 0; i < n; ++i) {
         res++;
         if(res == A.end())
            res = A.begin();
      }      
   } else if(n < 0) {
      for(int i = n; i < 0; ++i) {
         if(res == A.begin()) 
            res = A.end();
         res--;
      }
   }
   return res;
}

void print(list<int> &A) {
   foreach(it,A)
      printf("%d ",*it);
   putchar('\n');
}

bool josephus(int n, int m) {
   list<int> A;
   list<int>::iterator it;
   for(int i = 1; i <= n; ++i)
      A.push_back(i);
   it = A.begin();
   for(int i = 1; sz(A) > 1; ++i) {      
      if(i % m == 0) {
         print(A);
         if(sz(A) > 0) 
            it = A.erase(it);
         list<int>::iterator p = next(A,it,m - 1);
         it = A.insert(it,*p);
         p = next(A,it,m);
         if(sz(A) > 0) it = A.erase(p);
         DEBUG(*p);
         print(A);
      } else {
         it++;
      }
      if(it==A.end())
         it = A.begin();
   }
   
   return A.front();
}

int main(int argc, char *argv[]) {
   int n = 5, m = 2;
   DEBUG(josephus(n,m));
/*   
   list<int> A;
   list<int>::iterator it, prev;
   for(int i = 1; i <= 5; ++i)
      A.push_back(i);
   prev = it = A.begin();
   prev++; DEBUG(*prev);
   it++; it++; it++; DEBUG(*it);
   A.insert(prev,*it);
   A.erase(prev);
   A.erase(it);
   for(list<int>::iterator t = A.begin(); t != A.end(); ++t)
      printf("%d ",*t);
   putchar('\n');
  */ 
   
   /*
   while(1==scanf("%d",&n)) {
      if(n==0) break;
      printf("%d\n",A[n]);
   }
   */
   return 0;
}
/* @END_OF_SOURCE_CODE */
