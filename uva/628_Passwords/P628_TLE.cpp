/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  628  C++  "Backtracking" */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
#define BITCOUNT(mask) ( __builtin_popcount((mask)) )
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

const int maxn = 102;
string buf, word, rule, dict[maxn];
char tpl[1024];
int P[] = {0,9,99,999,9999,99999,999999,9999999};

int main(int argc, char *argv[]) {	
	int N, M;
	while(getline(cin,buf)) {
		sscanf(buf.c_str(),"%d",&N);
		for(int i = 0; i < N; ++i) {
			getline(cin,word);
			dict[i] = word;
		}
		getline(cin,buf);
		sscanf(buf.c_str(),"%d",&M);
		puts("--");
		for(int i = 0; i < M; ++i) {
			getline(cin,rule);
			for(int j = 0; j < N; ++j) {
				string s = rule;
				vector<int> vz;
				size_t pos = 0;
				while((pos=s.find('#',pos))!=string::npos) {
					s = s.replace(pos,1,dict[j]);
					pos+=dict[j].size();
				}
				for(int j = 0; j < s.size(); ++j) {
					if(s[j]=='0') 
						vz.push_back(j);
				}
				int opt = vz.size();
				if(opt==1) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%d",i);
						s[vz[0]] = tpl[0];
						puts(s.c_str());
					}				
				} else if(opt==2) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%02d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						puts(s.c_str());
					}				
				} else if(opt==3) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%03d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						s[vz[2]] = tpl[2];
						puts(s.c_str());
					}			
				} else if(opt==4) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%04d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						s[vz[2]] = tpl[2];
						s[vz[3]] = tpl[3];
						puts(s.c_str());
					}								
				} else if(opt==5) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%05d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						s[vz[2]] = tpl[2];
						s[vz[3]] = tpl[3];
						s[vz[4]] = tpl[4];
						puts(s.c_str());
					}
				} else if(opt==6) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%06d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						s[vz[2]] = tpl[2];
						s[vz[3]] = tpl[3];
						s[vz[4]] = tpl[4];
						s[vz[5]] = tpl[5];
						puts(s.c_str());
					}				
				} else if(opt==7) {
					for(int i = 0; i <= P[opt]; ++i) {
						sprintf(tpl,"%07d",i);
						s[vz[0]] = tpl[0];
						s[vz[1]] = tpl[1];
						s[vz[2]] = tpl[2];
						s[vz[3]] = tpl[3];
						s[vz[4]] = tpl[4];
						s[vz[5]] = tpl[5];
						s[vz[6]] = tpl[6];
						puts(s.c_str());
					}
				}
				
			}
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
