/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10896  C++  "Ad Hoc, String Manipulation" */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
   int TC;
   string text;
   string word;
   scanf("%d\n",&TC);
   while(TC-- > 0) {
      getline(cin,text);
      getline(cin,word);
      for(int i = 0; i < 26; ++i) {
         string s = " "+text+" ";
         for(int j = 1; j < s.size()-1; ++j)
            if(isalpha(s[j]))
               s[j] = 'a'+((26+s[j]-'a'-i)%26);   
         if(s.find(" "+word+" ") != string::npos) putchar('a'+i);
      }
      putchar('\n');
   }
   return 0;
}

