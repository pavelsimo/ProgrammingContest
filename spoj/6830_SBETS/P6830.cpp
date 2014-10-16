/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ SBETS C++ "Ad Hoc" */
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


int main(int argc, char *argv[]) {
   int TC, ga, gb;
   string buf, team_a, team_b, res;
   cin >> TC;
   while(TC-- > 0) {
      map<string,bool> m_teams;
      res = "";
      for(int i = 0; i < 16; ++i) {
         cin >> team_a >> team_b >> ga >> gb;
         if(m_teams.count(string(team_a))==0) 
            m_teams[string(team_a)] = true;
         if(m_teams.count(string(team_b))==0) 
            m_teams[string(team_b)] = true;
         if(ga < gb) 
            m_teams[team_a] = false;
         else 
            m_teams[team_b] = false;
      }
      foreach(it,m_teams) {
         if(it->second) 
            res = it->first;
      }
      puts(res.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
