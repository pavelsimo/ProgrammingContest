/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  401  C++  "String Manipulation" */
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

#define PALINDROME 1
#define MIRRORED_STRING 2
#define MIRRORED_PALINDROME 3
char rev[256];

int ismirror(char *s, int n) {
	int m = n/2;
	FOR(i,0,m) 
		if(rev[s[i]]!=s[n-i-1]) 
			return 0;
	return 1;
}

int ispal(char *s, int n) {
	int m = n/2;
	FOR(i,0,m) 
		if(s[i]!=s[n-i-1]) 
			return 0;
	return 1;
}

int main(int argc, char *argv[]) {
	char word[32];
	int ans, n;
	memset(rev,0,sizeof(rev));
	
	rev['A'] = 'A';
	rev['E'] = '3';
	rev['H'] = 'H';
	rev['I'] = 'I';
	rev['J'] = 'L';
	rev['L'] = 'J';
	rev['M'] = 'M';
	rev['O'] = 'O';
	rev['S'] = '2';
	rev['T'] = 'T';
	rev['U'] = 'U';
	rev['V'] = 'V';
	rev['W'] = 'W';
	rev['X'] = 'X';
	rev['Y'] = 'Y';
	rev['Z'] = '5';
	rev['1'] = '1';
	rev['2'] = 'S';
	rev['3'] = 'E';
	rev['5'] = 'Z';
	rev['8'] = '8';
	
	while(gets(word)) {
		ans = 0;
		n = strlen(word);
		if(ismirror(word,n)) ans|=MIRRORED_STRING;
		if(ispal(word,n)) ans|=PALINDROME;
		switch(ans) {
			case PALINDROME:
				printf("%s -- is a regular palindrome.\n", word);
			break;
			case MIRRORED_STRING:
				printf("%s -- is a mirrored string.\n", word);
			break;
			case MIRRORED_PALINDROME:
				printf("%s -- is a mirrored palindrome.\n", word);
			break;
			default:
				printf("%s -- is not a palindrome.\n", word);
			break;
		}
		putchar('\n');
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */

