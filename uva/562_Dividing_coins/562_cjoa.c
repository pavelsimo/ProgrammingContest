#include <stdio.h>

int a[50001];

int main() {
  int n, m;
  int i, j;
  int s, sum;
  int coin;

  scanf("%d", &n);
  while (n-- > 0) {
    for (s = 1; s < 50001; ++s)
      a[s] = 0;
    a[sum = 0] = 1;
    scanf("%d", &m);
    for (i = 0; i < m; ++i) {
      scanf("%d", &coin);
      for (s = sum; s >= 0; --s) {
        if (a[s])
          a[s+coin]++;
      }
      sum += coin;
    }
    for (s = sum/2; s >= 0; --s)
      if (a[s])
        break;
    printf("%d\n", sum-2*s);
  }

  return 0;
}
