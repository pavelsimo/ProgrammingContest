#include <iostream>
#include <cmath>

using namespace std;

typedef long long llong;

double EPS = 1e-5;
double INF = 100000000000000000;
double X[102];

double dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main(int argc, char *argv[]) {
    double vb, vs, xu, yu;
    int n, res;
    cin >> n >> vb >> vs;
    for(int i = 0; i < n; ++i)
        cin >> X[i];
    cin >> xu >> yu;
    double best = INF, bestU = INF;
    res = 0;
    for(int i = 1; i < n; ++i) {
        double tu = dist(X[i], 0, xu, yu)/vs;
        double t = X[i]/vb + tu;
        if(t < best - EPS) {
            res = i;
            best = t;
            bestU = tu;
        } else if(fabs(t - best) <= EPS && tu < bestU - EPS) {
            res = i;
            best = t;
            bestU = tu;          
        }
    }
    cout << res + 1 << endl;
    return 0;
}
