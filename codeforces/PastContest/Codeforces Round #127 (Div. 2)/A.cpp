#include <iostream>

using namespace std;

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   string s, res = "";
   cin >> s;
   char ch = s[0];   
   int n = s.size();
   for(int i = 0; i < n; ++i)
      if(s[i] > ch) 
         ch = s[i];
   for(int i = 0; i < n; ++i)
      if(ch == s[i]) 
         res += ch;
   cout << res << endl;
   return 0;
}

