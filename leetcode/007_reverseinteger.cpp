/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int n = x;
        long long res = 0;        
        while(n) {
            int d = n % 10;
            res = res*10LL + d;
            n /= 10;
        }        
        if (res > (1LL << 31LL) - 1LL)
            res = 0LL;
        if (res < -(1LL << 31LL))
            res = 0LL;        
        return (int) res;
    }
};

int main() {

    Solution s;

    cout << s.reverse(-123) << endl;

    return 0;
}
