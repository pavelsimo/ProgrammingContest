#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct cmp {
	bool operator()(const string &a, const string &b) const {
		return a+b < b+a;
	}
};

int main(int argc, char *argv[]) {
	int N, M;
	string dict[20], buf, best, s;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&N);
	while(N-- > 0) {
		getline(cin,buf);
		istringstream in(buf);
		in >> M;
		for(int i = 0; i < M; ++i)
			in >> dict[i];
		sort(dict,dict+M,cmp());
		best="";
		for(int i = 0; i < M; ++i)
			best+=dict[i];
		puts(best.c_str());
	}
	return 0;
}
