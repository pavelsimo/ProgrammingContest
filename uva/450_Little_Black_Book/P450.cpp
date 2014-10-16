/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  450  C++  "Ad Hoc, Sorting" */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

struct Employee {
   string title, firstname, lastname, homeaddress, department, homephone, workphone, campusbox;
   Employee(string _title, string _firstname, string _lastname, string _homeaddress, string _department, 
               string _homephone, string _workphone, string _campusbox) : title(_title), firstname(_firstname), 
                  lastname(_lastname), homeaddress(_homeaddress), department(_department), 
                     homephone(_homephone), workphone(_workphone), campusbox(_campusbox) {}
   bool operator<(const Employee &T) const {
      return lastname < T.lastname;
   }
};

vector<Employee> emp;

int main(int argc, char *argv[]) {
   int TC;
   string buf;
   string title, firstname, lastname, homeaddress, department, homephone, workphone, campusbox;
   getline(cin,buf);
   sscanf(buf.c_str(),"%d",&TC);
   while(TC-- > 0) {
      getline(cin,department);
      while(getline(cin,buf)) {
         if(!buf.size()) break;
         istringstream in(buf);
         getline(in,title,',');
         getline(in,firstname,',');
         getline(in,lastname,',');
         getline(in,homeaddress,',');
         getline(in,homephone,',');
         getline(in,workphone,',');
         getline(in,campusbox,',');
         emp.push_back(Employee(title, firstname, lastname, homeaddress, department, homephone, workphone, campusbox));
      }
   }
   sort(all(emp));
   for(int i = 0; i < sz(emp); ++i) {
      printf("----------------------------------------\n");
      printf("%s %s %s\n",emp[i].title.c_str(),emp[i].firstname.c_str(),emp[i].lastname.c_str());  
      printf("%s\n",emp[i].homeaddress.c_str());
      printf("Department: %s\n",emp[i].department.c_str());
      printf("Home Phone: %s\n",emp[i].homephone.c_str());
      printf("Work Phone: %s\n",emp[i].workphone.c_str());
      printf("Campus Box: %s\n",emp[i].campusbox.c_str());
   }
   return 0;
}
/* @END_OF_SOURCE_CODE */
