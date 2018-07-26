class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1)
            return;
        
        vector<int> cols, rows;
        
        for(int i = 0; i < matrix.size(); ++i)
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            if(matrix[i][j] == 0)
            {
                cols.push_back(i);
                rows.push_back(j);
            }
        }
        
        for(int col: cols)
        for(int j = 0; j < matrix[0].size(); ++j)
            matrix[col][j] = 0;
            
        for(int row: rows)
        for(int i = 0; i < matrix.size(); ++i)
            matrix[i][row] = 0;
    
        return;       

    }
};