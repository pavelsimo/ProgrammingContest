/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  540  C++  "Queue" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

int main(int argc, char *argv[]) {
   int N, M, x, TC=0;
   int V[1001];
   string buffer, op;
   while ( scanf("%d", &N) == 1 ) {
      if ( N == 0 ) break;
      printf("Scenario #%d\n",++TC);
      map<int,int> group; // element_id => group_id
      map<int,list<int>::iterator> pos; // group_id   => currentpos_id
      list<int> Q;
      for(int i = 0; i < N; ++i) {
         scanf("%d",&M);
         for(int j = 0; j < M; ++j) {
            scanf("%d",&x);
            group[x] = i;
         }  
         pos[i] = Q.end();
         V[i] = 0;
      }
      while(getline(cin,buffer)) {
         if ( buffer[0] == 'S' ) break;
         if ( buffer[0] == 'E' ) {
            istringstream stream(buffer);
            stream >> op >> x;
            if ( group.find(x) == group.end() ) {
               Q.push_back(x);
            } else {
               if ( V[group[x]] <= 0 ) {
                  pos[group[x]] = Q.insert(Q.end(),x);
                  V[group[x]]++;
               } else { 
                  pos[group[x]]++;
                  pos[group[x]] = Q.insert(pos[group[x]], x);
                  V[group[x]]++;
               }
            }
         } else if ( buffer[0] == 'D' ) {
            if ( !Q.empty() ) {
               printf("%d\n",Q.front());
               V[group[Q.front()]]--;
               Q.pop_front();
            }
         }
      }
      printf("\n");
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
