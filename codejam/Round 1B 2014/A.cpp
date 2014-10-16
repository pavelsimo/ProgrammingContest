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



string get_base_str(string a) {
   int f1[256];
   memset(f1, 0, sizeof(f1));
   string res = "";
   for(int i = 0; i < sz(a); ++i) {
      if(f1[(int)a[i]] == 0) res += a[i];
      f1[(int)a[i]]++;
   }
   return res;
}

bool is_possible(string a, string b) {
   set<char> S1, S2;
   for(int i = 0; i < sz(a); ++i) S1.insert(a[i]);
   for(int i = 0; i < sz(b); ++i) S2.insert(b[i]);
   if(S1!=S2) return false;
   string a2 = get_base_str(a);
   string b2 = get_base_str(b);
   int i, j;
   for(i = 0, j = 0; i < sz(b2); ++i) {
      if(j < sz(a2)) {
         if(a2[j] == b2[i]) ++j;
      }
   }
   if(j != sz(a2)) return false;
   return true;
}



int get_cost(string a, string b) {
   int f1[256], f2[256];
   memset(f1, 0, sizeof(f1));
   memset(f2, 0, sizeof(f2));
   for(int i = 0; i < sz(a); ++i) f1[(int)a[i]]++;
   for(int i = 0; i < sz(b); ++i) f2[(int)b[i]]++;
   int res = 0;
   for(int i = 0; i < 256; ++i) res += abs(f1[i] - f2[i]);
   return res;
}


int freq[102][26];

int main(int argc, char *argv[]) { 
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    vector<string> A;
    string S;
    int N; 
    memset(freq, 0, sizeof(freq));
    cin >> N;
    for(int i = 0; i < N; ++i) {
       cin >> S;
       A.push_back(S);
    }
    int ans = 10000002;
    for(int i = 0; i < N; ++i) {
       int cost = 0;
       bool ok = true;
       for(int j = 0; j < N; ++j) {
          if(i == j) continue;
          if(is_possible(A[i], A[j])) {
             cost += get_cost(A[i], A[j]);
          } else {
             ok = false;
             break;
          }
       }
       if(ok) {
          ans = min(ans, cost);
       }
    }
    printf("Case #%d: ", tc);
    if(ans >= 10000002) printf("Fegla Won\n");
    else printf("%d\n",ans);
  }
  return 0;
}
