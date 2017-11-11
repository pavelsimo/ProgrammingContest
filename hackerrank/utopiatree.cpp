/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int cycle(int k) {
    int size = 1;
    for(int i = 1; i <= k; ++i) {
        if(i & 1) size *= 2;
        else ++size;
    }
    return size;
}

int main(){
    int TC;
    cin >> TC;
    for(int tc = 0; tc < TC; tc++){
        int n;
        cin >> n;
        cout << cycle(n) << endl;
    }
    return 0;
}

