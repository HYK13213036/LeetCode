class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));   // 初始化二维矩阵
        for(int i = 0;i < m; ++i){
            for(int j = 0;j < n; ++j){
                if(DFS(board, word, 0, i, j, visited))   //从每个点出发沿四个方向进行DFS
                    return true;
            }
        }
        return false;    // 不满足的话就为False
    }
    
private:
    bool DFS(vector<vector<char>>& board, string word, int index, int i, int j,                      vector<vector<bool>>& visited){
        if(index == word.size()) return true;  // 终止条件
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
                 || visited[i][j] || board[i][j] != word[index]) // i,j的范围，标志位和字符匹配
            return false;
        
        visited[i][j] = true; //设置标志位，接下来进行DFS
        bool result = DFS(board, word, index + 1, i + 1, j, visited)
            || DFS(board, word, index + 1, i, j + 1, visited)
            || DFS(board, word, index + 1, i - 1, j, visited)
            || DFS(board, word, index + 1, i, j - 1, visited);
        visited[i][j] = false;  //回溯完，将标志位恢复
        return result;
    }
};