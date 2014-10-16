/* @BEGIN_OF_SOURCE_CODE */
/* @SPOJ ABSYS C++ "Ad Hoc" */
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
   int TC;
   string s, A, B, C, del;
   getline(cin,s);
   sscanf(s.c_str(),"%d",&TC);
   getline(cin,s);
   while(TC-- > 0) {
      getline(cin,s);
      istringstream in(s);
      in >> A >> del >> B >> del >> C;
      if(C.find("machula") != string::npos)
         printf("%s + %s = %d\n",A.c_str(),B.c_str(),atoi(A.c_str()) + atoi(B.c_str()));
      else if(B.find("machula") != string::npos)
         printf("%s + %d = %s\n",A.c_str(),atoi(C.c_str())-atoi(A.c_str()),C.c_str());
      else if(A.find("machula") != string::npos)
         printf("%d + %s = %s\n",atoi(C.c_str())-atoi(B.c_str()),B.c_str(),C.c_str());
      else
         printf("%s + %s = %s\n",A.c_str(),B.c_str(),C.c_str());
      getline(cin,s);
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
