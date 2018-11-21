class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0)
            return;
        int left=0;
        int right=n-1;
        int i=left;
        while(i <= right){
            if(nums[i] == 0){
                swap(nums[i], nums[left]); //交换过来的是零正好，
                i++;
                left++;
            }
            else if(nums[i] == 1)
                i++;
            else if(nums[i] == 2){
                swap(nums[i], nums[right]);   //有可能交换过来的是2
                right--;
            }
        }
    }
};