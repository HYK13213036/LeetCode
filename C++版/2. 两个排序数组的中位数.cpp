class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> C;
        int i, j;
        int mid = (m+n) / 2 + 1;
        for(i=0, j=0;i<m && j<n;){
            if(A[i] > B[j]){
                C.push_back(B[j++]);
            }
            else{
                C.push_back(A[i++]);
            }
            if(C.size() == mid){
                break;
            }
        }
        while(C.size() != mid){
            if(i < m)
                C.push_back(A[i++]);
            if(j < n)
                C.push_back(B[j++]);
        }
        if ((m+n) % 2 == 0)
            return (C[C.size()-1] + C[C.size()-2]) / 2.0;
        return *(C.end()-1);
    }
};