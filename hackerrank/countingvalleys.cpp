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

int main() {
    
    int n;
    cin >> n;
    
    string s;    
    cin >> s;

    int level = 0;
    bool bsl = false;
    int res = 0;
    for(int i = 0; i < n; ++i) {

        if(s[i] == 'D') {
            level--;
        } else if (s[i] == 'U') {
            level++;
        }

        if (level < 0) {
            bsl = true;
        }
        
        if (level >= 0) {
            if(bsl) {
                res++;
            }
            bsl = false;            
        }
    }

    printf("%d\n", res);

    return 0;
}
