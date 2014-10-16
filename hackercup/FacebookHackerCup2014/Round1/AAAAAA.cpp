#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<sstream>
#include<map>

using namespace std;

typedef long long llong;

string board[602];
bool seen[602][602];
int N, M;

int main() {
	int TC;
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc) {
		cin >> N >> M;
		memset(seen, false, sizeof(seen));
		for(int i = 0; i < N; ++i) {
			cin >> board[i];
		}
	}
	return 0;
}
