/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10718  C++  "Bit Mask" */
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

#define N 4

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

int V[32769]; 
int dx[] = {+1,-1,+0,+0};
int dy[] = {+0,+0,+1,-1};
int D[6][4] = {
				 {1,2,4,3},
				 {3,4,5,0},
				 {4,3,5,0},
				 {2,1,5,0},
				 {1,2,5,0},
				 {1,2,3,4},
				};
struct node {
	int i;
	int j;
	int sboard;
	int sdice;
	int dpos;
	node() : 
		i(0), j(0), sboard(0), sdice(0), dpos(0){}
	node(int _i, int _j, int _sboard, int _sdice, int _dpos) : 
		i(_i), j(_j), sboard(_sboard), sdice(_sdice), dpos(_dpos) {}
};



int move(queue<node> &Q, int i, int j, int board, int dice, int dpos, int dir) {
	int nboard = board;
	int ndice = dice;
	int ndpos = D[dpos][dir];
	if ( (nboard&(1<<(i*N+j))) != 0 ) {				
		if ( (ndice&(1<<ndpos)) != 0 ) {
			// B 1 
			// D 1
		} else {
			// B 1
			// D 0
			ndice  |= 1<<ndpos;
			nboard &= ~(1<<(i*N+j));					
		}
	} else {
		if ( (ndice&(1<<ndpos)) != 0 ) {
			// B 0
			// D 1
			// If a flea is on the side of a die that is moved to the floor, it jumps from the die to the tile. 
			ndice  &= ~(1<<ndpos);
			nboard |= 1<<(i*N+j);
		} else {
			// B 0
			// D 0
		}
	}
	
	printf("pos=%d dice=%d board=%d v[nboard]=%d\n",ndpos, ndice, nboard, V[nboard]);
	
	/*
	if ( V[nboard] == -1 ) {
		
		V[nboard] = V[board]+1;
		Q.push(node(i,j,nboard,ndice,dpos));           
	}
	*/
	return nboard;
}

int main() {
	int TC, sboard, x, y, found;
	char ch, s[10];
	//scanf("%d\n",&TC);
	
	//TEST
	queue<node> Q;
	move(Q,2,0,2296,0,0,UP);
	move(Q,1,0,2296,0,3,RIGHT);
	move(Q,1,0,2280,0,2,RIGHT);
	
	// END TEST
	
	/*
	while (TC-- > 0) {
		queue<node> Q;
		sboard = 0;
		found = 0;
		memset(V,-1,sizeof(V));
		
		for(int i = 0; i < N; ++i) {
			scanf("%s",&s);
			for(int j = 0; j < N; ++j ) {
				ch = s[j];
				if ( ch == 'X' ) sboard |= (1<<(i*N+j));
				if ( ch == 'D' ) { 
					x = i; 
					y = j;
				}
			}
		}
		
		Q.push(node(x,y,sboard,0, 0));
		V[sboard] = 0;
		int k = 0;
		
		while(!Q.empty()) {
			node ns = Q.front();
			Q.pop();
			if ( ns.sboard == 0 ) {
				found = 1;
				printf("%d\n",V[ns.sboard]);
				break;
			}
			for(int i = 0; i < N; ++i) {
				int ndx = ns.i + dx[i];
				int ndy = ns.j + dy[i];
				int ndpos = dice[ns.dpos][i];
				int nsdice = ns.sdice;
				int nsboard = ns.sboard;
				if(ndx < 0 || ndx >= N || ndy < 0 || ndy >= N) continue;
				
				// move
			}
		}
		if (!found)
			printf("impossible\n");
	}
	*/
	
}
/* @END_OF_SOURCE_CODE */
