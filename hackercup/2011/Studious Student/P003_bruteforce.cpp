#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

string dict[20];
int id[20];
string buf, best, s;

int main(int argc, char *argv[]) {
	int N, M;
	getline(cin,buf);
	sscanf(buf.c_str(),"%d",&N);
	while(N-- > 0) {
		getline(cin,buf);
		istringstream in(buf);
		in >> M;
		best = "";
		for(int i = 0; i < M; ++i) {
			in >> dict[i];
			best+=dict[i];
			id[i] = i;
		}
		do {
			s="";
			for(int i = 0; i < M; ++i)
            s+=dict[id[i]];
			if(s < best)
				best = s;
		} while(next_permutation(id,id+M));
		puts(best.c_str());
	}
	return 0; 
}
/* @END_OF_SOURCE_CODE */

