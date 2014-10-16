/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  630  C++  "Ad Hoc, Anagrams" */
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

typedef vector<int> VI;

map<string,VI> m_id;
vector<string> dict;
string buf;

int main(int argc, char *argv[]) {
   int TC, N;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   for(int tc = 0; tc < TC; ++tc) {
      if(tc > 0) putchar('\n');
      m_id.clear();
      dict.clear();
      getline(cin,buf);
      getline(cin,buf);
      sscanf(buf.c_str(),"%d",&N);
      for(int i = 0; i < N; ++i) {
         getline(cin,buf);
         dict.push_back(buf);
         sort(all(buf));
         m_id[buf].push_back(i);
      }
      while(getline(cin,buf)) {
         if(buf[0]=='E') break;
         string word = buf;
         sort(all(word));
         vector<int> a = m_id[word];
         printf("Anagrams for: %s\n",buf.c_str());
         if(sz(a) > 0) {
            for(int i = 0; i < sz(a); ++i)
               printf("%*d) %s\n",3,i+1,dict[a[i]].c_str());              
         } else {
            printf("No anagrams for: %s\n",buf.c_str());
         }
      }
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
