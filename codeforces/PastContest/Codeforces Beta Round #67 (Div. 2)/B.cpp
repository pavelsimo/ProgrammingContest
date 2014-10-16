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

map<string, int> m_users;
vector<pair<int, string> > ans;

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
   if(a.first != b.first) return a.first > b.first;
   return a < b;
}

int main(int argc, char *argv[]) {
   int n;
   string buf, you, u, v, action, dumb;
   getline(cin, you);
   getline(cin, buf);
   sscanf(buf.c_str(), "%d", &n);
   for(int i = 0; i < n; ++i) {
      getline(cin, buf);
      istringstream in(buf);
      in >> u >> action;
      if(action[0] == 'p') { // +15
         in >> dumb >> v;
         v = v.substr(0,sz(v)-2);
         if(u == you || v == you)
            m_users[u] += 15, m_users[v] += 15;
         else
            m_users[u] += 0,  m_users[v] += 0;
      } else if(action[0] == 'c') { // +10
         in >> dumb >> v;
         v = v.substr(0,sz(v)-2);
         if(u == you || v == you)
            m_users[u] += 10, m_users[v] += 10;
         else
            m_users[u] += 0,  m_users[v] += 0;
      } else if(action[0] == 'l') { // +5
         in >> v;
         v = v.substr(0,sz(v)-2);
         if(u == you || v == you)
            m_users[u] += 5, m_users[v] += 5;
         else
            m_users[u] += 0,  m_users[v] += 0;
      }
   }
   foreach(it, m_users)
      ans.push_back(make_pair(it->second, it->first));
   sort(all(ans), cmp);
   for(int i = 0; i < sz(ans); ++i) {
      if(ans[i].second == you) continue;
      cout << ans[i].second << endl;
   }
   return 0;
}

 
