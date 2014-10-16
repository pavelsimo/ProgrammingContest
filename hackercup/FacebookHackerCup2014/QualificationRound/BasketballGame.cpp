#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct Player {
	string name;
	int shot_per, height, cur_time;
	int draft_number;
	Player(string nname="", int nshot_per=0, int nheight=0, int ncur_time=0) {
		name = nname;
		shot_per = nshot_per;
		height = nheight;
		cur_time = ncur_time;
		draft_number = 0;
	}
};

bool cmp1(const Player &A, const Player &B) {
	if(A.shot_per != B.shot_per) return A.shot_per > B.shot_per;
	return A.height > B.height;
}

bool cmp2(const Player &A, const Player &B) {
	if(A.cur_time != B.cur_time) return A.cur_time < B.cur_time;
	return A.draft_number < B.draft_number;
}

Player players[64], team_a[32], team_b[32];
int N, M, P, nteam_a, nteam_b;

void solve(Player *team, int SZ) {
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < P; ++j)
			team[j].cur_time++;
		sort(team, team + P, cmp2); // [0, P)
		sort(team + P, team + SZ, cmp2); // [P, N/2)
		swap(team[P-1], team[P]);
	}
}

int main() {
	int TC;
	cin >> TC;
	for(int tc = 1; tc <= TC; ++tc) {
		cin >> N >> M >> P;
		string name;
		for(int i = 0; i < N; ++i) {
			cin >> players[i].name >> players[i].shot_per >> players[i].height;
		}
		sort(players, players + N, cmp1);
		nteam_a = nteam_b = 0;

		for(int i = 0; i < N; ++i) 
			players[i].draft_number = i;
		
		for(int i = 0; i < N; ++i) {
			if(i & 1) team_b[nteam_b++] = players[i];
			else team_a[nteam_a++] = players[i];
		}
		
		if(P < nteam_a) solve(team_a, nteam_a);
		if(P < nteam_b) solve(team_b, nteam_b);
		
		vector<string> res;
		for(int i = 0; i < P; ++i) {
			res.push_back(team_a[i].name);
			res.push_back(team_b[i].name);
		}
		sort(res.begin(), res.end());
		cout << "Case #" << tc << ":";
		for(int i = 0; i < (int) res.size(); ++i) {
			cout << ' ';
			cout << res[i];
		}
		cout << endl;
	}   
   return 0;
}
