/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  11074  C++  "Ad Hoc, Greedy" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

string s, A[102];
map<string, int> m_inv;

int inv_cost(const string &s) {
   int res = 0;
   for(int i = 0; i < sz(s); ++i) {
      for(int j = i + 1; j < sz(s); ++j) {
         if(s[i] > s[j]) res++;
      }
   }
   return res;
}

bool cmp_sortedness(const string &a, const string &b) {
   return m_inv[a] < m_inv[b];
}

int main(int argc, char *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int TC, N, M;
   getline(cin, s);
   sscanf(s.c_str(),"%d", &TC);
   while(TC-- > 0) {
      getline(cin, s);
      getline(cin, s);
      m_inv.clear();
      sscanf(s.c_str(),"%d%d", &N, &M);
      for(int i = 0; i < M; ++i) {
         getline(cin, A[i]);
         if(!m_inv.count(A[i]))
            m_inv[A[i]] = inv_cost(A[i]);
      }
      //  if two or more strings are equally sorted, 
      //  list them in the same order they are in the input file. 
      stable_sort(A, A + M, cmp_sortedness);
      for(int i = 0; i < M; ++i)
         cout << A[i] << '\n';
      if(TC) cout << '\n';
   }
	return 0;
}
/* @END_OF_SOURCE_CODE */
