/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  496  C++  "Math, Sets" */
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
   string s1, s2;
   int ai, bi, N;
   while(getline(cin, s1)) {
      vector<int> A, B;
      getline(cin, s2);
      istringstream in1(s1); 
      istringstream in2(s2); 
      while(in1 >> ai) A.push_back(ai);
      while(in2 >> bi) B.push_back(bi);
      sort(all(A)); sort(all(B));
      vector<int> C(min(A.size(), B.size()));
      N = set_intersection (all(A), all(B), C.begin()) - C.begin();
      C.resize(N);
      if(A == C && B == C) cout << "A equals B" << endl;
      else if(A == C) cout << "A is a proper subset of B" << endl;
      else if(B == C) cout << "B is a proper subset of A" << endl;
      else if(N == 0) cout << "A and B are disjoint" << endl;
      else cout << "I'm confused!" << endl;
   }

   return 0;
}
/* @END_OF_SOURCE_CODE */
