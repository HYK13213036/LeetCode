class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < board.size();i++){
            unordered_map<char, bool> row;
            unordered_map<char, bool> col;
            unordered_map<char, bool> cube;
            for(int j = 0;j < board[0].size();j++){
                if(board[i][j] != '.'){
                    if(row[board[i][j]] == true)   //检查每一行
                        return false;
                    else
                        row[board[i][j]] = true;
                }
                if(board[j][i] != '.'){
                    if(col[board[j][i]] == true)
                        return false;
                    else
                        col[board[j][i]] = true;
                }
                if(board[i/3*3+j/3][i%3*3+j%3] != '.'){
                    if(cube[board[i/3*3+j/3][i%3*3+j%3]] == true)
                        return false;
                    else
                        cube[board[i/3*3+j/3][i%3*3+j%3]] = true;
                }               
            }
        }
        return true;
    }
};