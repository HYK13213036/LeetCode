class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0;i <= nums.size(); ++i){
            DFS(nums, 0, nums.size(), i);   // 从nums[0]开始，并且size是从小到大的
        }
        return res;
    }
    
    void DFS(vector<int>& nums, int start, int n, int size){
        if(size < 0) return;
        if(size == 0){
            res.push_back(group);
            return;
        }
        for(int i = start;i < n; i++){
            group.push_back(nums[i]);
            DFS(nums, i+1, n, size-1);   // i是在变化的
            group.pop_back();    // 回溯
        }
    }
    
private:
    vector<vector<int>> res;
    vector<int> group;
};