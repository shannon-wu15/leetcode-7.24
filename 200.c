class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int ret = 0;
        if(grid.empty() || grid[0].empty())
            return ret;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i ++)
        {
            for(int j = 0; j < n; j ++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j, m, n);
                    ret ++;
                }
            }
        }
        return ret;
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        grid[i][j] = '0';
        if(i > 0 && grid[i-1][j] == '1')
            dfs(grid, i-1, j, m, n);
        if(i < m-1 && grid[i+1][j] == '1')
            dfs(grid, i+1, j, m, n);
        if(j > 0 && grid[i][j-1] == '1')
            dfs(grid, i, j-1, m, n);
        if(j < n-1 && grid[i][j+1] == '1')
            dfs(grid, i, j+1, m, n);
    }
};