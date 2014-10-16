/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  12577  C++  "Ad hoc, Strings" */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
   string s;
   int tc = 1;
   while(cin >> s) {
      if(s[0] == '*') break;
      printf("Case %d: Hajj-e-%s\n",tc, s == "Hajj" ? "Akbar" : "Asghar");
      tc++;
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
