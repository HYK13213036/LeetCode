class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0;i < m;i++)
            for(int j = 0; j < n;j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[0][0] == 0) dp[i][j] = 1;
                }
                else{
                    if(obstacleGrid[i][j])   continue;
                    if(i && obstacleGrid[i-1][j] == 0) dp[i][j] += dp[i-1][j]; //向下走
                    if(j && obstacleGrid[i][j-1] == 0) dp[i][j] += dp[i][j-1]; //向右走
                }
            }
        return dp[m-1][n-1];
    }
};