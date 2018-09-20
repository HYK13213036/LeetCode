class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        int *a = new int[n];
        for(int i = 0;i < n;i++) a[i] = nums[i];
        sort(nums.begin(), nums.end());
        int lhs = 0, rhs = n -1;  //从两边开始查找
        while(rhs > lhs){
            if(nums[rhs] + nums[lhs] > target) rhs--;
            else if(nums[rhs] + nums[lhs] < target) lhs++;
            else{
                int id1, id2;
                for(int i = 0;i < n; i++){
                    if(a[i] == nums[lhs]){
                        id1 = i+1;
                        break;
                    }
                }
                for(int i = n - 1;i >= 0; i--){
                    if(a[i] == nums[rhs]){
                        id2 = i+1;
                        break;
                    }
                }
                res.push_back(min(id1, id2));
                res.push_back(max(id1, id2));
                return res;
            }
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> hashmap;
        vector<int> res;
        for(int i = 0;i < numbers.size();i++){
            if(hashmap.find(target-numbers[i]) != hashmap.end()){
                res.push_back(hashmap[target-numbers[i]]+1);
                res.push_back(i+1);
                return res;
            }
            hashmap[numbers[i]] = i;
        }
        return res;
    }
};