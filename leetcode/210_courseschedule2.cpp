/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
    
    VI seen;
    VI mark;
    VVI adj;    
        
    bool hascycle(int u) {
        if (seen[u])
            return mark[u] == true;
        seen[u] = true;
        mark[u] = true;
        int res = false;
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            res |= hascycle(v);
        }
        mark[u] = false;
        return res;
    }
    
    void toposort(int u, stack<int> &seq) {
        if (seen[u])
            return;
        seen[u] = true;
        for(int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            toposort(v, seq);
        }
        seq.push(u);
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = numCourses;
        adj = VVI(n);
        for(int i = 0; i < prerequisites.size(); ++i) {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            adj[v].push_back(u);
        }

        seen = VI(n, 0);
        mark = VI(n, 0);
        vector<int> res;        
        for(int u = 0; u < n; ++u) {
            if (hascycle(u))
                return res;
        }

        seen = VI(n, 0);
        stack<int> seq;
        for(int u = 0; u < n; ++u) {
            toposort(u, seq);
        }
        
        while(!seq.empty()) {
            int u = seq.top();
            seq.pop();
            res.push_back(u);
        }

        return res;
    }
};
