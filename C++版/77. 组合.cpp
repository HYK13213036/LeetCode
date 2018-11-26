class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        DFS(n, 1, k);
        return res;
    }
    
    void DFS(int n, int start, int size){
        if(size < 0) return;
        if(size == 0){
            res.push_back(group);
            return;
        }
        for(int i = start;i <= n; i++){
            group.push_back(i);
            DFS(n, i+1, size-1);
            group.pop_back();
        }
    }
private:
    vector< vector<int> > res;
    vector<int> group;
};