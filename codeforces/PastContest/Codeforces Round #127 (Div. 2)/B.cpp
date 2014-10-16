#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()

vector<string> archive[12];
vector<string> problem;
map<string, int> ord;

int get_inv(vector<string> &a) {
   int res = 0;
   for(int i = 0; i < sz(a); ++i) {
      for(int j = i + 1; j < sz(a); ++j) {
         if(ord[a[j]] < ord[a[i]]) res++;  
      }
   }
   return res;
}

int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(0);
   int n, m, k;   
   string s;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> s;
      problem.push_back(s);
      ord[s] = i;
   }
   cin >> m;
   for(int i = 0; i < m; ++i) {
      cin >> k;
      for(int j = 0; j < k; ++j) {
         cin >> s;
         archive[i].push_back(s);
      }
   }
   int p = 0;
   int best = 0;
   for(int i = 0; i < m; ++i) {
      sort(all(problem));
      do {
         int k = 0;
         for(int j = 0; j < sz(archive[i]) && k < sz(problem); ++j)
            if(problem[k] == archive[i][j]) 
               k++;         
         if(k == sz(problem)) {
            int t = n*(n-1)/2 - get_inv(problem) + 1;
            if(t > p) {
               p = t;
               best = i;   
            }            
         }
      } while(next_permutation(all(problem)));
   }
   if(p > 0)
      cout << best + 1 << endl << "[:" << string(p, '|') << ":]" << endl;
   else
      cout << "Brand new problem!" << endl;
   return 0;
}

