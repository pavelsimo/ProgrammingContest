#include <stdio.h>
#include "string.h"
#define m 10007

int n, a0, b0, c0, a1, b1, c1, an, bn, cn;
int ma[2][2], mat[2][2], matt[2][2];

void Pot(int a) {
	if (a == 1)
		memcpy(mat, ma, sizeof(ma));
	else {
		Pot(a / 2);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++) {
				int v = 0;
				for (int k = 0; k < 2; k++)
					v += (mat[i][k] * mat[k][j]) % m;
				matt[i][j] = v % m;
			}
		memcpy(mat, matt, sizeof(matt));
		if (a % 2) {
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++) {
					int v = 0;
					for (int k = 0; k < 2; k++)
						v += (mat[i][k] * ma[k][j]) % m;
					matt[i][j] = v % m;
				}
			memcpy(mat, matt, sizeof(matt));
		}
	}
}
int main() {
	scanf("%d%d%d%d", &n, &a0, &b0, &c0);
	a1 = 3 * (b0 + c0);
	a1 %= m;
	b1 = 3 * (a0 + c0);
	b1 %= m;
	c1 = 3 * (a0 + b0);
	c1 %= m;
	if (n == 0)
		printf("%d %d %d", a0, b0, c0);
	else if (n == 1) {
		printf("%d %d %d", a1, b1, c1);
	} else {
		ma[0][0] = 3;
		ma[0][1] = 18;
		ma[1][0] = 1;
		Pot(n - 1);
		an = (a1 * mat[0][0] + a0 * mat[0][1]) % m;
		bn = (b1 * mat[0][0] + b0 * mat[0][1]) % m;
		cn = (c1 * mat[0][0] + c0 * mat[0][1]) % m;
		printf("%d %d %d", an, bn, cn);
	}
	return 0;
}

