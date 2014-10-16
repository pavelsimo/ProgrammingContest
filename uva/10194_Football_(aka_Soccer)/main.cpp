/* @BEGIN_OF_SOURCE_CODE */
/* @JUDGE_ID:  10194  C++  "Sorting" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;
#define FOR(i,x,y) for(int i=(int)(x);i<=(int)(y);++i)
#define REP(i,n) FOR(i,0,n-1)
#define FORD(i,x,y) for(int i=(int)(x);i>=(int)(y);--i)
#define ALL(a) (a).begin(),(a).end()
#define FORE(t,i) for(typeof(t.begin())i=t.begin();i!=t.end();++i)

struct Team {
	string name;
	int wins;
	int ties;
	int losses;
	int goal_scored;
	int goal_against;
	Team(const string &_name) : 
		name(_name), wins(0), ties(0), 
		losses(0), goal_scored(0), goal_against(0) {}
	bool operator< (const Team &t) const {
		if ( 3*wins+ties != 3*t.wins+t.ties ) 
			return 3*t.wins+t.ties < 3*wins+ties;
		if ( wins != t.wins )
			return t.wins < wins;
		if ( goal_scored-goal_against != t.goal_scored-t.goal_against ) 
			return t.goal_scored-t.goal_against < goal_scored-goal_against;
		if ( goal_scored !=  t.goal_scored ) 
			return t.goal_scored < goal_scored;
		if ( wins+ties+losses != t.wins+t.ties+t.losses ) 
			return t.wins+t.ties+t.losses > wins+ties+losses;
		return strcasecmp(name.c_str(), t.name.c_str()) < 0;
	}
};

int main(int argc, char *argv[]) {
	int ntournament, nteams, ngames;
	string tournament, team_name, games;
	scanf("%d\n",&ntournament);
	REP(tc,ntournament) {
		if (tc!=0) printf("\n");
		map<string, int> index;
		vector<Team> rank;
		getline(cin,tournament);
		scanf("%d\n",&nteams);
		REP(i,nteams) {
			getline(cin,team_name);
			Team x(team_name);
			index[team_name] = i;
			rank.push_back(x);
		}
		scanf("%d\n",&ngames);
		REP(i,ngames) {
			string teamA, teamB, score, temp;
			int teamA_score, teamB_score;
			getline(cin,games);
			istringstream cin_games(games);
			getline(cin_games, teamA, '#');
			getline(cin_games, score, '#');
			getline(cin_games, teamB, '#');
			istringstream cin_score(score);
			getline(cin_score, temp, '@');
			istringstream(temp) >> teamA_score;
			getline(cin_score, temp, '@');
			istringstream(temp) >> teamB_score;
			if ( teamA_score > teamB_score ) {
				rank[index[teamA]].wins++;
				rank[index[teamB]].losses++;
			} else if ( teamA_score < teamB_score ) {
				rank[index[teamA]].losses++;
				rank[index[teamB]].wins++;				
			} else {
				rank[index[teamA]].ties++;
				rank[index[teamB]].ties++;				
			}
			rank[index[teamA]].goal_scored  += teamA_score;
			rank[index[teamA]].goal_against += teamB_score;
			rank[index[teamB]].goal_scored  += teamB_score;
			rank[index[teamB]].goal_against += teamA_score;			
		}
		sort(rank.begin(), rank.end());
		printf("%s\n",tournament.c_str());
		REP(i,rank.size()) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				i+1, 
				rank[i].name.c_str(), 
				rank[i].wins*3+rank[i].ties, 
				rank[i].wins+rank[i].ties+rank[i].losses, 
				rank[i].wins, 
				rank[i].ties, 
				rank[i].losses,
				rank[i].goal_scored-rank[i].goal_against,
				rank[i].goal_scored, 
				rank[i].goal_against);
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */

