class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
       int l1 = 0,r1 = n-1,l2 = 0,r2 = n-1;
         while(l1 <= r1){
              int mid = l1 + (r1-l1)/2;
              if(nums[mid] < target) l1 = mid+1;
              else r1 = mid-1;
         }
         while(l2 <= r2){
              int mid = l2+(r2-l2)/2;
              if(nums[mid] > target) r2=mid-1;
              else l2=mid + 1;
         }
         vector<int> res(2,-1);
         if(l1 <= r2)  res[0] = l1,res[1] = r2;
         return res;
    }
};