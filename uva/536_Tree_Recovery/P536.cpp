/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  536  C++  "Binary Tree, Recursion" */
#include <iostream>
#include <string>

using namespace std;

void go(int n, string s1, string s2, string &ans) {
     if(n <= 0) return;
     int p = s2.find(s1[0]);
     go(p,s1.substr(1),s2,ans);
     go(n-p-1,s1.substr(p+1),s2.substr(p+1),ans);
     ans+=s1[0];
}

int main(int argc, char *argv[]) {
	string s1,s2,ans;
	while( cin >> s1 >> s2 ) {
		ans="";
		go(s1.size(),s1,s2,ans);
		cout << ans << endl;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

