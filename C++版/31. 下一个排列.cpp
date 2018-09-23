class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
      void reverse(vector<int>& nums, int start) {
        int i = start, j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 2;
        while(n >= 0 && nums[n+1] <= nums[n]){
            n--;   //寻找后者大于前者的位置
        }
        if(n >= 0){
            int j = nums.size()-1;
            while(j >= 0 && nums[j] <= nums[n]){
                j--;   //从最右边向左搜索
            }
            swap(nums, n, j);
        }
        reverse(nums, n+1);  //最后进行翻转
    }
};