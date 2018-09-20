class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
           vector<vector<int> > ans;
           sort(num.begin(),num.end());
           for(int i=0;i+2<num.size();i++){
               int l=i+1,r=num.size()-1;
               while(l<r){
                  while(l < r && num[i] + num[l] + num[r] > 0) r--;
                    if(l==r) break; //注意判断下相等的时候break。
                  if(num[i] + num[l] + num[r]==0){
                    ans.push_back(vector<int> { num[i], num[l], num[r]});
                    while(l<r&&num[l+1]==num[l]) l++;
                  }
                  l++;
               }
               while(i+1 < num.size()&&num[i+1] == num[i]) i++;
           }
           return ans;
    }
};