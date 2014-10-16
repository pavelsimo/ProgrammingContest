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

int main() {
   string buf;
   int TC, N, value, p_blue, p_orange, b_cnt, o_cnt, time;
   char type;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   int tc = 1;
   while(TC-- > 0) {
      vector<char> seq;
      vector<int> pos;
      getline(cin,buf);
      istringstream in(buf);
      in >> N;
      for(int i = 0; i < N; ++i) {
         in >> type >> value;
         seq.push_back(type);
         pos.push_back(value);
      }
      time = 0;
      b_cnt = o_cnt = 0;
      p_blue = p_orange = 1;
      for(int i = 0; i < N; ++i) {
         char ch = seq[i];
         int p = pos[i];
         if(ch=='B') {
            int dst = max(0,abs(p_blue - p) - o_cnt) + 1; 
            b_cnt+=dst;
            time+=dst;
            o_cnt = 0;
            p_blue = p;
         } else {
            int dst = max(0,abs(p_orange - p) - b_cnt) + 1;
            o_cnt += dst;
            time+=dst;
            b_cnt = 0;
            p_orange = p;
         }
      }
      printf("Case #%d: %d\n",tc++,time);
   }
   return 0;
}
