class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int l = 0, r = len-1, maxarea = 0;
        while(r>l){
            maxarea = max(maxarea , min(height[l], height[r]) * (r-l));
            height[l] <= height[r] ? l++ : r--;
          
        }
        return maxarea;
    }
};