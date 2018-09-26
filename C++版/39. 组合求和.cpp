class Solution {
    vector<int> d;
    vector<vector<int> > res;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0);
        return res;
    }
    void dfs(vector<int> &candidates, int sum, int target, int step)
    {
        if(sum > target|| target < 0) return ;
        if(sum == target){res.push_back(d); return;}
        else
        {
            int i;
            for(i=step;i<candidates.size();i++)
            {
                d.push_back(candidates[i]);
                dfs(candidates, sum + candidates[i], target, i);
                d.pop_back();
            }
        }
    }
};