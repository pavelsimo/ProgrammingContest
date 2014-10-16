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

typedef pair<int, string> Allies; // id_allie + artifact
typedef pair<string, int> CArtifact; // artifact + frequency

map<Allies, int> m_allies;
map<string, vector<CArtifact> >  X;
vector<string> lst, ca_lst;
vector<pair<string,int> > ans[102];

int main(int argc, char *argv[]) {
   string buf, ba, ca, cca, token;
   int k, n, m, q, cost, id;
   getline(cin, buf);
   sscanf(buf.c_str(),"%d%d%d%d",&k,&n,&m,&q);
   for(int i = 0; i < n; ++i) {
      getline(cin, ba);
      lst.push_back(ba);
   }
   for(int i = 0; i < m; ++i) {
      getline(cin, buf);
      istringstream in(buf);
      getline(in, ca, ':');
      ca_lst.push_back(ca);
      lst.push_back(ca);
      getline(in, cca, ':');
      istringstream in2(cca);
      while(getline(in2, token, ',')) {
         istringstream in3(token);
         in3 >> ba >> cost;
         X[ca].push_back(make_pair(ba,cost));
      }
   }
   for(int i = 0; i < q; ++i) {
      getline(cin, buf);
      istringstream in(buf);
      in >> id >> ba;
      m_allies[make_pair(id, ba)]++;
   }
   for(int i = 0; i < sz(ca_lst); ++i) {
      string ca_str = ca_lst[i];
      vector<CArtifact> CA = X[ca_str];
      for(int id_allie = 1; id_allie <= k; ++id_allie) {
         int mi = 0x3f3f3f3f;
         for(int j = 0; j < sz(CA); ++j) {
            int allie_avl = m_allies[make_pair(id_allie, CA[j].first)] / CA[j].second;
            mi = min(mi, allie_avl);
         }         
         if(mi > 0) {
            for(int j = 0; j < sz(CA); ++j)
               m_allies[make_pair(id_allie, CA[j].first)] -= mi * CA[j].second;
            m_allies[make_pair(id_allie, ca_str)] += mi;
         }
      }
   }
   sort(all(lst));
   for(int id_allie = 1; id_allie <= k; ++id_allie) {
      for(int j = 0; j < sz(lst); ++j) {
         if(m_allies[make_pair(id_allie, lst[j])] > 0) {
            ans[id_allie].push_back(make_pair(lst[j], m_allies[make_pair(id_allie, lst[j])]));
         }
      }
   }
   for(int i = 1; i <= k; ++i) {
      cout << sz(ans[i]) << endl;
      for(int j = 0; j < sz(ans[i]); ++j) {
         cout << ans[i][j].first << " " << ans[i][j].second << endl;
      }
   }
   return 0;
}

