#include <iostream>
#include <cstdio>
#include <cfloat>
#include <algorithm>
#include <cmath>

using namespace std;

double cost_per_farm, rate_gain_per_farm, target_cookies;

int main() {
  int TC;
  cin >> TC;
  for(int tc = 1; tc <= TC; ++tc) {
    cin >> cost_per_farm >> rate_gain_per_farm >> target_cookies;
    double ans = DBL_MAX;
    double time = 0;
    double current_rate = 2.0;
    for(int i = 0; i <= 100000; ++i) {
      ans = min(ans, time + (target_cookies / current_rate));
      time += (cost_per_farm / current_rate);
      current_rate += rate_gain_per_farm;
    }
    printf("Case #%d: %.7lf\n", tc, ans);
  }
  return 0;
}
