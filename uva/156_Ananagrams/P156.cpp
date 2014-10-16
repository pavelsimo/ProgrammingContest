/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  156  C++  "Ad Hoc, String Manipultion, Anagrams" */
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

vector<string> dict;
map<string, int> freq;

int main(int argc, char *argv[]) {
   string buf, word;
   while(getline(cin,buf)) {
      if(buf[0]=='#') break;
      istringstream in(buf);
      while(in >> word) {
         dict.push_back(word);
         transform(all(word),word.begin(),::tolower);
         sort(all(word));
         freq[word]++;
      }
   }   
   sort(all(dict));
   for(int i = 0; i < sz(dict); ++i) {
      string s = dict[i];
      transform(all(s),s.begin(),::tolower);
      sort(all(s));
      if(freq[s] == 1) 
         puts(dict[i].c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
