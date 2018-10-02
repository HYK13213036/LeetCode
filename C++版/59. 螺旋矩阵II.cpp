class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int count = 1;
        for (int left = 0, right = res[0].size() - 1,
                 top = 0, bottom = res.size() - 1;
             left <= right && top <= bottom;
             ++left, --right, ++top, --bottom) {

            for (int j = left; j <= right; ++j) {
                res[top][j] = count++;
            }
            for (int i = top + 1; i < bottom; ++i) {
                res[i][right] = count++;
            }
            for (int j = right; top < bottom && j >= left; --j) {
                res[bottom][j] = count++;
            }
            for (int i = bottom - 1; left < right && i > top; --i) {
                res[i][left] = count++;
            }
        }
        return res;
    }
};