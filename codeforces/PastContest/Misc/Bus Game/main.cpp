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
#include <bitset>
using namespace std;


int main() {
   vector<int> A, B;
   A.push_back(2); A.push_back(1);  A.push_back(0);  // 100
   B.push_back(2); B.push_back(12); B.push_back(22); // 10
   int X, Y;
   bool player = true;
   int N = A.size();
   cin >> X >> Y;
   while(true) {
		bool play = false;
		if(player) {
			for(int i = 0; i < N; ++i) {
				if(X-A[i] >=0 && Y-B[i] >= 0) {
					X-=A[i];
					Y-=B[i];
					play = true;
					break;
				}
			}
		} else {
			for(int i = N-1; i >= 0; --i) {
				if(X-A[i] >=0 && Y-B[i] >= 0) {
					X-=A[i];
					Y-=B[i];
					play = true;
					break;
				}
			}
		}
		if(!play) break;
		player = !player;
   }
   if(!player) cout << "Ciel" << endl;
   else cout << "Hanako" << endl;
   return 0;
}
/* @END_OF_SOURCE_CODE */
