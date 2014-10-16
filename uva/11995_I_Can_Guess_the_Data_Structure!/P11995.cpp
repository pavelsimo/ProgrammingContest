/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11995  C++  "Ad Hoc, Data Structure" */
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
#include <regex.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define C_INS 1
#define C_DEL 2

int N;

int main(int argc, char *argv[]) {
   int cmd, x;
   bool b_pq, b_q, b_s;
   while(1==scanf("%d",&N)) {
      priority_queue<int> PQ;
      queue<int> Q;
      stack<int> S;
      b_pq = b_q = b_s = true;
      while(N-- > 0) {
         scanf("%d%d",&cmd,&x);     
         if(cmd==C_INS) {
            PQ.push(x);
            Q.push(x);
            S.push(x);
         } else if(cmd==C_DEL) {
            int t;
            // priority queue
            if(PQ.empty()) {
               b_pq = false;
            } else {
               t = PQ.top();
               PQ.pop();
               if(t != x) b_pq = false;
            }
            // queue
            if(Q.empty()) {
               b_q = false;
            } else {
               t = Q.front();
               Q.pop();
               if(t != x) b_q = false;
            }
            // stack
            if(S.empty()) {
               b_s = false;
            } else {
               t = S.top();
               S.pop();
               if(t != x) b_s = false;
            }
         }
      }
      if(b_pq && !b_q && !b_s) {
         puts("priority queue");
      } else if(!b_pq && b_q && !b_s) {
         puts("queue");
      } else if(!b_pq && !b_q && b_s) {
         puts("stack");
      } else if(!b_pq && !b_q && !b_s) {
         puts("impossible");
      } else {
         puts("not sure");
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

