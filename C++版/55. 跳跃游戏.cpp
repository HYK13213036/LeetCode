class Solution {
public
    bool canJump(vectorint& nums) {
      int maxReach = 0;
      for(int i=0;inums.size() && i=maxReach;i++)
         maxReach = max(maxReach,i+nums[i]);   跳到该点后还能到达的极限
      if(maxReachnums.size()-1)
         return false;
      return true; 
    }
};