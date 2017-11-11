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
    int days;
    cin >> days;
    
    int likes = 0;
    int people = 5;

    while(days-- > 0) {
        people = people / 2;
        likes += people;
        people = people * 3;
    }

    cout << likes << endl;
    
    return 0;
}
