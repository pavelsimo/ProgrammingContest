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
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }


struct node {
	string country;
	string name;
	node(string _country, string _name) {
	country = _country;
	name = _name;
  }  
};

bool operator== (const node &a, const node &b) {
  if ( a.country == b.country && a.name == b.name ) 
    return true;
  return false;
}

bool operator< (const node &a, const node &b) {
  return true;
}

int main(int argc, char *argv[]) {
	int TC;
	string line, token, country, name;
	set<node> s;
	map<string, int> m;
	set<node>::iterator s_it;	
	map<string, int>::iterator m_it;
	scanf("%d\n",&TC);
	while ( TC-- > 0 ) {
		getline(cin, line);
		stringstream stream(line);
		for(int i = 0; stream >> token; ++i) {
			if ( i == 0 ) country = token;
			else name+=token;
		}
		s.insert(node(country,name));
	}
	for(s_it = s.begin(); s_it != s.end(); ++s_it)
		m[s_it->country]++;
	for(m_it = m.begin(); m_it != m.end(); ++m_it)
		cout << m_it->first << " " << m_it->second << endl;
	return 0;
}
