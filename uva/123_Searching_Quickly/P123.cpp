/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  123  C++  "Data Structures, Map, Sorting" */
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

typedef long long llong;

set<string> S;
vector<string> ST;
map<string, vector<pair<int,int> > > m_id;

void rpl(string &s, const string &from, const string &to, size_t pos = 0) {
   if((pos = s.find(from, pos)) != string::npos) {
      s.replace(pos, from.length(), to);
      pos += to.length();
   }
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s, word;
   while(getline(cin,s)) {
      if(s[0] == ':') break;
      S.insert(s);
   }
   for(int i = 0; getline(cin,s); ++i) {
      std::transform(all(s), s.begin(), ::tolower);
      ST.push_back(s);
      istringstream in(s);
      int cnt = 0;
      while(in >> word) {
	 if(S.count(word)) continue;
	 m_id[word].push_back(make_pair(i, cnt));
	 cnt += word.size();
	 cnt++;
      }
   }
   foreach(it, m_id) {
      string word = it->first;
      vector<pair<int,int> > adj = it->second; 
      for(int i = 0; i < sz(adj); ++i) {
	 string st = ST[adj[i].first];
	 string to = word;
	 std::transform(all(to), to.begin(), ::toupper);
	 rpl(st, word, to, adj[i].second);
	 cout << st << '\n';
      } 
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */

