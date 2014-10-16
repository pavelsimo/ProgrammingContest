#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int comp(const void *a, const void *b) { return *(char*) b - *(char*) a; }
int comp2(const void *a, const void *b) { return *(char*) a - *(char*) b; }
 
int main() {
    char n[16];
    long long a, b; /* Can overflow in the case 1999999999 */
    int l, c;
    while (scanf("%s", n) == 1) {
          l = strlen(n);
          qsort(n, l, sizeof(char), comp);
          fputs(n, stdout); fputs(" - ", stdout);
          a = strtoll(n, NULL, 10);
          qsort(n, l, sizeof(char), comp2);
          b = 0; while (n[b] == '0') b++;
          if (b < l) c = n[b], n[b] = n[0], n[0] = c;
          fputs(n, stdout); fputs(" = ", stdout);
          b = strtoll(n, NULL, 10);
          printf("%lld = 9 * %lld\n", a - b, (a - b) / 9);
    }
    return 0;
}
