/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10008  C++  "Sorting, Counting Frequency" */
#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)

#define N 26
int idx[N];

struct node {
	char ch;
	int feq;
	node(char _ch) : 
		ch(_ch), feq(1) {}
	bool operator< (node T) const {
		if (feq != T.feq) return T.feq < feq;
		return T.ch > ch;
	}
	bool operator== (node T) const {
		return ch == T.ch;
	}
};

int main(int argc, char *argv[]) {
	int TC, k=0;
	string s;
	vector<node> a;
	memset(idx,-1,sizeof(idx));
	scanf("%d\n",&TC);
	while(TC-- > 0) {
		getline(cin,s);
		REP(i,s.length()) {
			char ch = toupper(s[i]);
			if(isalpha(s[i])) {
				if ( idx[ch-'A'] == -1 ) {
					idx[ch-'A'] = k++;
					a.push_back(node(ch));
				} else {
					a[idx[ch-'A']].feq++;
				}
			}
		}
	}
	sort(a.begin(),a.end());
	REP(i,a.size())
		printf("%c %d\n",a[i].ch, a[i].feq);
	return 0;
}
/* @END_OF_SOURCE_CODE */
