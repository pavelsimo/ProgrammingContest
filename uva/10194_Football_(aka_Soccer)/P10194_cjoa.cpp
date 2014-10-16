/* @JUDGE_ID: 1131EP  10194  C++  "Sorting" */
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstring>
 
using namespace std;
 
struct Team {
   string name;
   int wins, ties, losses;
   int goals_scored, goals_allowed;
   Team(const string& _nm)
      : name(_nm), wins(0), ties(0), losses(0),
        goals_scored(0), goals_allowed(0) {}
   void update(int gs, int ga) {
      goals_scored  += gs;
      goals_allowed += ga;
      if (gs == ga)
         ++ties;
      else if (gs > ga)
         ++wins;
      else
         ++losses;
   }
   bool operator< (const Team& t) const {
      if (wins*3 + ties != t.wins*3 + t.ties)
         return wins*3 + ties > t.wins*3 + t.ties;
      if (wins != t.wins)
         return wins > t.wins;
      if (goals_scored - goals_allowed != t.goals_scored - t.goals_allowed)
         return goals_scored - goals_allowed > t.goals_scored - t.goals_allowed;
      if (goals_scored != t.goals_scored)
         return goals_scored > t.goals_scored;
      if (wins + ties + losses != t.wins + t.ties + t.losses)
         return wins + ties + losses < t.wins + t.ties + t.losses;
      return strcasecmp(name.c_str(), t.name.c_str()) < 0;
   }
};
 
int main(int argc, char* argv[]) {
   istringstream is;
   string line;
 
   int N;
   getline(cin, line);
   is.str(line);
   is >> N;
   while (N-- > 0) {
      getline(cin, line);
      cout << line << endl;
 
      int T;
      getline(cin, line);
      is.clear();
      is.str(line);
      is >> T;
 
      map<string, int> team_idx;
      vector<Team> teams;
      for (int i = 0; i < T; ++i) {
         string name;
         getline(cin, name);
         team_idx[name] = teams.size();
         teams.push_back(Team(name));
      }
 
      int G;
      getline(cin, line);
      is.clear();
      is.str(line);
      is >> G;
      for (int j = 0; j < G; ++j) {
         getline(cin, line);
         size_t p = line.find('#');
         string t1(line, 0, p);
         ++p;
         int g1 = atoi(line.c_str()+p);
         
         p = line.find('@', p);
         ++p;
         int g2 = atoi(line.c_str()+p);
         p = line.find('#', p);
         ++p;
         string t2(line, p);
 
         int i1 = team_idx[t1];
         int i2 = team_idx[t2];
         teams[i1].update(g1, g2);
         teams[i2].update(g2, g1);
      }
 
      sort(teams.begin(), teams.end());
      for (int i = 0; i < T; ++i) {
         printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
                i+1, teams[i].name.c_str(),
                teams[i].wins*3+teams[i].ties,
                teams[i].wins+teams[i].ties+teams[i].losses,
                teams[i].wins,teams[i].ties,teams[i].losses,
                teams[i].goals_scored-teams[i].goals_allowed,
                teams[i].goals_scored,teams[i].goals_allowed);
      }
 
      if (N)
         putchar('\n');
   }
   return 0;
}