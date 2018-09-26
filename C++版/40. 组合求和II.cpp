class Solution {
    vector<int> d;
    vector<vector<int>> res;
    set<vector<int>> s;
public:
    void dfs(vector<int>& candidates, int sum, int target, int step){
        if(sum > target || target < 0)  { return; }
        if(sum == target) {s.insert(d); return;}
        int i = 0;
        for(i = step;i < candidates.size();i++){      
            d.push_back(candidates[i]);
            step ++;
            dfs(candidates, sum+candidates[i], target, step);
            d.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, 0);
        set< vector<int> >::iterator it;
        for(it=s.begin();it!=s.end(); res.push_back(*it),it++);
        return res;
    }
};