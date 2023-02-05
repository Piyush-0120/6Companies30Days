/*
Maximum Sum of and Hourglass
https://leetcode.com/problems/maximum-sum-of-an-hourglass/

*/

class Solution {
public:
    int maxSum(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m-3+1;i++){
            for(int j=0;j<n-3+1;j++){
                int sum = a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};