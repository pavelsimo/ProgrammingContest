#include <iostream>
#include <list>
#include <map>
 
using namespace std;
 
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)
 
int main(int argc, char *argv[]) {
 
	list<int> a;
	map<int,list<int>::iterator> pos;
	pos[1] = a.insert(a.end(), 1);
	pos[2] = a.insert(a.end(), 2);
	pos[3] = a.insert(a.end(), 3);
	pos[4] = a.insert(a.end(), 4);
	pos[5] = a.insert(a.end(), 5);
	++pos[1];
	pos[1] = a.insert(pos[1], 11);
	FORE(a,it)
	   cout << *it << " ";
	cout << endl;
 
        return 0;
}