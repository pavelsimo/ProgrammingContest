/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 31; i >= 0; --i) {
            uint32_t mask = (1 << i);
            if ((n & mask) != 0) {
                res |= 1 << (31 - i);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(43261596) << endl;
}
