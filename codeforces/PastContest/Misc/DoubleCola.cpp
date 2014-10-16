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

typedef long long llong;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define DEBUG(x) cout << #x << ": " << x << endl
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define sz(a) int((a).size())

const char *names[] = {
  "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main() {
   int N;
   while(scanf("%d",&N)==1) {
      int j = 5;
      int k = 2;
      if(N <= 5) {
         puts(names[N-1]);   
      } else {
         for(int i = 10; true; i<<=1) {            
            j+=i;
            if(j >= N) {
               j-=i;
               break;
            }
            k<<=1;      
         }
         int index = 0;
         for(int i = k; true; i+=k) {
            if(N-j <= i) break;
            index++;
         }            
         puts(names[index]);
      }
   }
   return 0;
}
