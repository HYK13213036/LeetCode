class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int begin = 0,end = rows*cols-1;
        
        while(begin <= end)
        {
            int mid = (begin + end)/2;
            int row = mid/cols;
            int col = mid%cols;
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                begin = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};