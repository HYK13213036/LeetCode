class Solution {    
public:
    void dfs(vector<int>& nums, set< vector<int> >& res, int begin){   //一定不要忘了加上引用符号。。。
        if(begin == nums.size()){
            res.insert(nums);
        }
        for(int i = begin;i < nums.size(); i++){
            swap(nums[begin], nums[i]);
            dfs(nums, res, begin+1);
            swap(nums[begin], nums[i]);   //恢复原状
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        vector<vector<int>> ress;
        if(nums.size() == 0)
            return ress;
        sort(nums.begin(), nums.end());
        dfs(nums, res, 0);
        set<vector<int>>::iterator it;
        for(it = res.begin();it != res.end();ress.push_back(*it), it++);  //是不是有感觉了？都是套路
        return ress;
    }
};