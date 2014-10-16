/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  576  C++  "Dynamic Programming" */
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

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

using namespace std;

int p[] = {5,7,5};

bool is_vowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' 
		 || ch == 'o' || ch == 'u' || ch == 'y';
}

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string buf, s;
	int ans;
	while(getline(cin, buf)) {
		if(buf == "e/o/i") break;
		istringstream in(buf);
		for(ans = 0; getline(in, s, '/'); ++ans) {
			int prev = -2;
			int syllables = 0;
			for(int i = 0; i < sz(s); ++i) {
				if(is_vowel(s[i])) {
					if(i - 1 != prev) syllables++;
					prev = i;
				}
			}
			if(p[ans] != syllables) {
				cout << ans + 1 << '\n';
				break;
			}
		}
		if(ans >= 3)
			cout << 'Y' << '\n';
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
