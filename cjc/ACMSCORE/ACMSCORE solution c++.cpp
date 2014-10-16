#include <algorithm>
#include <stdio.h>
using namespace std;
#define Max 20
int casos, j = 0, times[Max], duration, P, solved, totalTime, penalty;
bool sol;
int main(int argc, char *argv[])
{
    //freopen("entrada.txt", "r", stdin);
    //freopen("salida.txt", "w", stdout);
    scanf("%d", &casos);
    while (casos--)
    {
        penalty = solved = 0;
        totalTime = 5;
        sol = true;
        scanf("%d%d", &duration, &P);
        for (int i = 0; i < P; i++)
            scanf("%d", &times[i]);
        // sorting times to solve every problem
        sort(times, times + P);
        for (int i = 0; i < P && sol; i++)
        {
            totalTime += times[i];
            sol = (totalTime <= duration);
            penalty += (sol * (totalTime));
            solved += (sol);
        }
        printf("Case #%d: %d %d\n", ++j, solved, penalty);
    }
    
    return 0;
}
