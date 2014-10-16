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

#define UP 0
#define BOTTOM 1
#define LEFT 2
#define RIGHT 3
#define FRONT 4
#define BACK 5
#define CCLOCKWISE 6

string rotate(string A, int dir) {
    string B = A;
    switch (dir) {
        case UP: {
            B[UP]=A[FRONT];
            B[FRONT]=A[BOTTOM];
            B[BOTTOM]=A[BACK];
            B[BACK]=A[UP];
            break;
        }
        case LEFT: {
            B[LEFT]=A[FRONT];
            B[FRONT]=A[RIGHT];
            B[RIGHT]=A[BACK];
            B[BACK]=A[LEFT];
            break;
        }
        case CCLOCKWISE: {
           B[UP]=A[RIGHT];
           B[RIGHT]=A[BOTTOM];
           B[BOTTOM]=A[LEFT];
           B[LEFT]=A[UP];
           break;
        }
    }
    return B;        
}

int main(int argc, char *argv[]) {
   int res = 0;
   string s;
   cin >> s;
   sort(all(s));
   do {
      bool ok = true;
      string t = s;
      for(int i = 0; i < 4; ++i) {
         for(int j = 0; j < 4; ++j) {
            for(int k = 0; k < 4; ++k) {
               if(t < s) ok = false;
               t = rotate(t,CCLOCKWISE);
            }
            t = rotate(t,LEFT);   
         }
         t = rotate(t,UP);
      }
      if(ok) res++;
   } while(next_permutation(all(s)));
   printf("%d\n",res);
   return 0;
}

