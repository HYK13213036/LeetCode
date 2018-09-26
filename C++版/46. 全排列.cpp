class Solution {
public:
    void dfs(vector<int> &num,vector<vector<int>> &res,int begin)
    {
        if(begin == num.size())
            res.push_back(num);
        for(int i=begin;i<num.size();i++)
        {
            swap(num[i],num[begin]);
            dfs(num,res,begin+1);
            swap(num[i],num[begin]);
        }
    }
    
    vector<vector<int> > permute(vector<int> &num)
    {
            vector<vector<int>> res;
            if(num.size()==0)
                return res;
            sort(num.begin(),num.end());
            dfs(num,res,0);
            return res;
    }
};