#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
   int n;
   map<string,int> M;
   string name;
   cin >> n;
   for(int i = 0; i < n; ++i) {
      cin >> name;
      if(M.count(name) == 0) {
         cout << "OK" << endl;
         M[name]++;
      } else {
         cout << name << M[name] << endl;
         M[name]++;
      }
   }
   return 0;
}

