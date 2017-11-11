/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:

    vector<int> seen;
    vector<int> mark;    
    VVI adj;
    
    bool hascycle(int u) {
        if (seen[u])
            return mark[u] == true;        
        seen[u] = true;
        mark[u] = true;
        bool res = false;
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            res |= hascycle(v);
        }
        mark[u] = false;
        return res;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        adj = VVI(n);
        for(int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            adj[v].push_back(u);
        }
        seen = VI(n, 0);
        mark = VI(n, 0);
        for(int i = 0; i < n; ++i) {
            if (hascycle(i))
                return false;
        }
        return true;
    }
};
