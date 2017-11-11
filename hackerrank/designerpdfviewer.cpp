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
    vector<int> heights(26);
    for(int i = 0; i < 26; i++){
       cin >> heights[i];
    }
    
    string word;
    cin >> word;

    int h = 0;
    int w = 0;
    for(int i = 0; i < word.length(); ++i) {
        int k = word[i] - 'a';
        w += 1;
        h = max(h, heights[k]);
    }
    printf("%d\n", w * h);
    
    return 0;
}
