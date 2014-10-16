/*
ID: 13
PROG: space
LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 1000
     
FILE *fin, *fout;
char sector[1+MAXN+1][1+MAXN+2+1];      /* extras form border of \0's */
int checked[1+MAXN+1][1+MAXN+2+1];      /* marks those squares we have checked */
     
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
int nmeteors;
 
void removeneighbors(int i, int j) {
    int k, i1, j1;
    checked[i][j] = nmeteors;
    sector[i][j] = '!';         /* seen this one! */
    for (k = 0; k < 4; k++) {
        i1 = i + dx[k];
        j1 = j + dy[k];
        if (checked[i1][j1] || sector[i1][j1] != '*') continue;
        removeneighbors(i1, j1);
    }
}
 
main() {
    int i, j, n;
    fin = fopen ("space.in", "r");
    fout = fopen ("space.out", "w");
    fscanf (fin, "%d", &n);
    for (i = 1; i <= n; i++)
        fscanf (fin, "%s", &sector[i][1]);
 
        /* count the meteors */
    nmeteors = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n;  j++) {
            if (sector[i][j] != '*') continue;
            nmeteors++;
            removeneighbors(i, j);
        }
    }
    fprintf (fout, "%d\n", nmeteors);
    exit (0);
}
