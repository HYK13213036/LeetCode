class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size();
        bool rowflag = false, columnflag = false;
        //防止覆盖
        for(int i = 0;i < row; i++)
            if(0 == matrix[i][0]){
                rowflag = true;
                break;
            }
        for(int j = 0;j < column; j++)
            if(0 == matrix[0][j]){
                columnflag = true;
                break;
            }
        //记录零位置
        for(int i = 1; i < row; i++)
            for(int j = 1; j < column; j++){
                if(0 == matrix[i][j]){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for(int i = 1; i < row; i++)
            for(int j = 1; j < column; j++){
                if(0 == matrix[i][0] || 0 == matrix[0][j])
                    matrix[i][j] = 0;
            }
        if(rowflag)
            for(int i = 0;i < row; i++)
                matrix[i][0] = 0;
        if(columnflag)
            for(int j = 0;j < column; j++)
                matrix[0][j] = 0;
        
    }
};