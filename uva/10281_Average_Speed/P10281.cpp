/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10281  C++  "Ad Hoc" */
#include <iostream>
#include <cstring> 
#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cmath>
#include <complex>
#include <stack>
using namespace std;

int main(int argc, char *argv[]) {
	string buf, token, stime, sspeed;
	int hh, mm, ss, speed=0;
	double ctime=0.0, time=0.0, dist=0.0, cdist=0.0;
	while(getline(cin,buf)) {
		istringstream in(buf);
		stime = sspeed = "";
		for(int i = 0; getline(in,token,' '); ++i) {
			if(i) sspeed = token;
			else stime = token;
		}
		sscanf(stime.c_str(),"%d:%d:%d",&hh,&mm,&ss);
		if(sspeed.size()!=0) { 
         dist += ((hh*3600.0 + mm*60.0 + ss - time)/3600.0)*speed;                           
         sscanf(sspeed.c_str(),"%d",&speed);
         time = hh*3600.0 + mm*60.0 + ss;
		} else {
			ctime = hh*3600.0 + mm*60.0 + ss;
			cdist = dist + (((ctime-time)*speed)/3600.0);
			printf("%s %.2lf km\n",stime.c_str(),cdist);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
