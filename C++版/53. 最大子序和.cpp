class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int sum = 0, max = nums[0];
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            if(max < sum) max = sum;
            if(sum < 0) sum = 0;    //如果累加和小于零，说明对后面的子串没有正收益，应舍弃
        }
        return max;
    }
};

// 动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1;i < nums.size(); i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);  //当前元素加上前面的元素与本身进行比较
            res = max(dp[i], res);
        }
        return res;
    }
};