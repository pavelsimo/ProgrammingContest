/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */

class Solution {
public:

    int dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& seen) {
        if (i < 0 || j < 0 || i >= n || j >= m || seen[i][j] || grid[i][j] != '1')
            return 0;
        int res = 1;
        seen[i][j] = 1;
        res += dfs(i + 1, j, n, m, grid, seen);
        res += dfs(i - 1, j, n, m, grid, seen);        
        res += dfs(i, j + 1, n, m, grid, seen);
        res += dfs(i, j - 1, n, m, grid, seen);                        
        return res;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > seen(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                seen[i].push_back(false);
            }            
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (!seen[i][j]) {
                    int cnt = dfs(i, j, n, m, grid, seen);
                    if (cnt > 0) {
                        ++res;
                    }                    
                }
            }            
        }
        return res;
    }
};
