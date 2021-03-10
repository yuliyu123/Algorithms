// https://leetcode.com/problems/number-of-islands/submissions/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j , row, col);   
                    ++count;
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col)
    {
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1') return; // // aleady visited or is not island(0), return
        grid[i][j] = '2';  // visited
        dfs(grid, i-1, j, row, col);
        dfs(grid, i+1, j, row, col);
        dfs(grid, i, j-1, row, col);
        dfs(grid, i, j+1, row, col);
    }
};
