/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  642  C++  "Count Frequency, Permutations" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
#include <list>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

#define SIZE 26

int compare(string s1, string s2) {
	int a[SIZE];
	int n = s1.length();
	int m = s2.length();
	if ( n != m ) return 0;
	memset(a,0,sizeof(a));
	for(int i = 0; i < n; ++i)
		a[s1[i]-'a']++;
	for(int i = 0; i < m; ++i)
		a[s2[i]-'a']--;
	for(int i = 0; i < SIZE; ++i)
		if ( a[i] != 0 ) return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	int found;
	string word;
	set<string> dictionary;
	while(getline(cin,word)) {
		if(word[0] == 'X') break;
		dictionary.insert(word);
	}
	while(getline(cin,word)) { 
		if(word[0] == 'X') break;
		found = 0;
		FORE(dictionary,it) {
			if ( compare(word,*it) ) {
				cout << *it << endl;		
				found = 1;
			}
		}
		if (!found)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

