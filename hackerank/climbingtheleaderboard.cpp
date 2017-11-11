/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<int> scores(n);
    vector<int> rank(n, 1);
    for(int i = 0; i < n; ++i) {
        cin >> scores[i];
    }    

    for(int i = 1; i < n; ++i) {
        if(scores[i-1] > scores[i]) {
            rank[i] = rank[i-1] + 1;
        } else {
            rank[i] = rank[i-1];
        }
    }

    reverse(rank.begin(), rank.end());
    reverse(scores.begin(), scores.end());
    
    int m;
    cin >> m;    
    vector<int> alice(m);
    for(int i = 0; i < m; ++i) {
        cin >> alice[i];
    }

    for (int i = 0; i < m; ++i) {
        auto lo = lower_bound(scores.begin(), scores.end(), alice[i]);        
        int ind = lo - scores.begin();
        
        if(ind >= n)
        {
            cout << 1 << endl;
        } else {
            int s = scores[ind];
            int a = alice[i];
            if (s > a) cout << rank[ind] + 1 << endl;
            else cout << rank[ind] << endl;
            
        }
    }    

    return 0;
}
