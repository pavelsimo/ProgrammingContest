/* ========================================================================
   $File: 
   $Date: 
   $Creator: Pavel Simo 
   ======================================================================== */


typedef vector<int> VI;
typedef vector<VI> VVI;

const int NDIR = 4;
int di[] = {+0, -1, +1, +0};
int dj[] = {+1, +0, +0, -1};

class Solution {
public:

    VVI seen;
    VVI A;
    int n, m;

    bool isvalid(int i, int j) {
        return !(i < 0 || i >= n || j < 0 || j >= m || seen[i][j] != -1 || A[i][j] != 1);
    }

    int perimeter(int i, int j) {
        if (!isvalid(i, j))
            return 0;
        
        seen[i][j] = 1;        
        int res = 4;
        for(int k = 0; k < NDIR; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            res += perimeter(ni, nj);            
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;                        
            if (A[ni][nj] == 1) --res;            
        }
        
        return res;
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        A = grid;
        n = grid.size();
        m = grid[0].size();
        seen = VVI(n, VI(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                seen[i][j] = -1;
            }
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if (A[i][j] == 1 && seen[i][j] == -1) {
                    res += perimeter(i, j);
                }
            }
        }
        
        return res;
    }
};
