/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12504  C++  "Tries, Prefix" */
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


map<string, string> parse_dict(const string &S) {
   map<string, string> X;
   string s = S.substr(1, S.size() - 2);
   string token, key, value;
   istringstream in(s);
   while(getline(in, token, ',')) {
      istringstream in2(token);
      getline(in2, key, ':');
      getline(in2, value, ':');
      X[key] = value;
   }
   return X;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC;
   string a, b;
   cin >> TC;
   while(TC-- > 0) {
      cin >> a >> b;
      map<string, string> m_old = parse_dict(a);
      map<string, string> m_new = parse_dict(b);
      int cnt = 0;
      bool changed = false;
      // + add
      foreach(it, m_new) {
         if(m_old.count(it->first) == 0) {
            changed = true;
            if(cnt == 0) cout << '+';
            else cout << ',';
            cout << it->first;
            cnt++;
         }
      }
      if(cnt > 0) cout << endl;
      // - del
      cnt = 0;
      foreach(it, m_old) {
         if(m_new.count(it->first) == 0) {
            changed = true;
            if(cnt == 0) cout << '-';
            else cout << ',';      
            cout << it->first;
            cnt++;                  
         }
      }
      if(cnt > 0) cout << endl;
      // * change
      cnt = 0;
      foreach(it, m_old) {
         if(m_new.count(it->first) != 0) {
            if(m_new[it->first] != it->second) {
               changed = true;
               if(cnt == 0) cout << '*';
               else cout << ',';      
               cout << it->first;
               cnt++;                
            }
         }
      }
      if(cnt > 0) cout << endl;
      if(!changed) cout << "No changes" << endl;
      cout << endl;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
