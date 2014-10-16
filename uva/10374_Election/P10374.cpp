/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  1180  C++  "Number Theory, Perfect Numbers" */
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

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef long long llong;

int main(int argc, char *argv[]) {
   int TC, N, M, cnt, ma;
   string s, res;
   string candidate, party;
   getline(cin, s);
   sscanf(s.c_str(), "%d", &TC);
   while(TC-- > 0) {
      map<string, int> m_votes;
      map<string, string> m_party;
      getline(cin, s);
      getline(cin, s);
      sscanf(s.c_str(), "%d", &N);
      cnt = ma = 0;
      for(int i = 0; i < N; ++i) {
         getline(cin, candidate);
         getline(cin, party);
         m_party[candidate] = party;
      }
      getline(cin, s);
      sscanf(s.c_str(), "%d", &M);
      for(int i = 0; i < M; ++i) {
         getline(cin, candidate);
         m_votes[candidate]++;
         ma = max(ma, m_votes[candidate]);
      }
      foreach(it, m_votes) {
         if(it->second == ma) {
            res = it->first;
            cnt++;
         }
      }
      if(cnt >= 2) cout << "tie" << endl;
      else cout << m_party[res] << endl;
      if(TC) cout << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
