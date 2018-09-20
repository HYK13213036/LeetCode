class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0, result = nums[0] + nums[1] + nums[2];
        vector< vector<int> > res;
        int n = nums.size();
        if(n < 4)
            return res;
        for(int i = 0;i < n-3;i++){
            for(int j = i+1;j < n;j++){
                int s = target - nums[i] - nums[j];   //变成两数之和的问题
                int l = j + 1, r = n - 1;
                while(l < r){
                    while(l < r && nums[l] + nums[r] > s) r--;
                    if(l== r) break;
                    if(nums[l] + nums[r] == s){
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(temp);
                        while(l < r && nums[l] == nums[l+1])
                            l++;
                    }
                    l++;
                }
                while(j < n-1 && nums[j] == nums[j+1]) 
                    j++;
            }
            while(i < n-4 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};