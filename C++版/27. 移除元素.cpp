class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];  //确定长度后面的值不予考虑
                n--;
            }
            else
                i++;         // 如果上面条件满足，则不会进行i++，所以下次仍然可以检查该元素
        }
        return n;
    }
};
