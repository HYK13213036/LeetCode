class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        const int k = 2; // At most k duplicated.

        int left = 0;
        int right = 1;

        for(; right < nums.size(); right++){
            if(nums[left] != nums[right] ||
              (left-k+1 < 0 || nums[left] != nums[left-k+1])){  //为了防止right-k+1无效，或上left-k+1 < = 0
                left ++;                                        //left-k+1<0使用什么的好
                nums[left] = nums[right];
            }
        }

        return left + 1; 
    }
};