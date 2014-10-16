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

struct Laptop {
   int speed, ram, hdd, cost;
   Laptop(int _speed = 0, int _ram = 0, int _hdd = 0, int _cost = 0) :
      speed(_speed), ram(_ram), hdd(_hdd), cost(_cost) {}
};

const int INF = 0x3f3f3f3f;
bool outdated[128];
Laptop A[128];

int main(int argc, char *argv[]) {
   int N;
   memset(outdated,false,sizeof(outdated));
   scanf("%d",&N);
   for(int i = 0; i < N; ++i)
      scanf("%d%d%d%d",&A[i].speed,&A[i].ram,&A[i].hdd,&A[i].cost);
   for(int i = 0; i < N; ++i) {
      for(int j = 0; j < N; ++j) {
         if(i == j) continue;
         if(A[i].speed < A[j].speed && A[i].ram < A[j].ram && A[i].hdd < A[j].hdd) {
            outdated[i] = true;
            break;
         }  
      }
   }
   int res = 0;
   int best = INF;
   for(int i = 0; i < N; ++i) {
      if(!outdated[i]) {
         if(A[i].cost < best) {
            res = i;
            best = A[i].cost;
         }
      }
   }
   printf("%d\n",res + 1);
   return 0;
}

