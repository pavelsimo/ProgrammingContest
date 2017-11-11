/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <iostream>
#include <string>

using namespace std;

int main() {

    string s;  
    while(cin >> s) {
        int hh = (s[0] - '0') * 10 + (s[1] - '0');
        int mm = (s[3] - '0') * 10 + (s[4] - '0');
        int ss = (s[6] - '0') * 10 + (s[7] - '0');

        if (hh < 12 && s[8] == 'P') hh += 12;        
        if (hh == 12 && s[8] == 'A') hh = 0;

        printf("%02d:%02d:%02d\n", hh, mm, ss);
    }

    return 0;
}
