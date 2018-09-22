class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 1;
        if(nums.size() == 0)
            return NULL;  
        for(int i = 1;i < nums.size();i++){
            if(nums[i-1] != nums[i]){
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};

