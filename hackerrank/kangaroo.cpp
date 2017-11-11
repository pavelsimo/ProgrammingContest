/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;


string kangaroo(int x1, int v1, int x2, int v2) {
    if (x1 > x2 && v1 > v2) return "NO";
    if (x1 < x2 && v1 < v2) return "NO";
    if (x1 == x2) return "YES";
    if (v1 == v2) return "NO";    
    if ((x2 - x1) % (v1 - v2) == 0) return "YES";
    return "NO";
}

int main() {
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%i %i %i %i", &x1, &v1, &x2, &v2);
    int result_size;
    string result = kangaroo(x1, v1, x2, v2);
    printf("%s\n", result.c_str());
    return 0;
}
