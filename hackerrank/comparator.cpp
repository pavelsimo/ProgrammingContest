/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool cmp(Player lhs, Player rhs) { 
    if (lhs.score != rhs.score)
        return lhs.score > rhs.score;
    return lhs.name < rhs.name; 
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; ++i){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }

    sort(players.begin(), players.end(), cmp);
    
    for(int i = 0; i < players.size(); ++i) {
        cout << players[i].name << " " << players[i].score << endl;
    }        
    
    return 0;
}
