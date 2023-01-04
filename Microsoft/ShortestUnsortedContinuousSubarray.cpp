/*
    Problem 10: Shortest Unsorted Continuous Subarray
    https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

*/
class Solution {
public:
    // T.C -> O(nlogn)
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>a=nums;
        // sorting the copied array 
        sort(a.begin(),a.end());
        int s=INT_MAX,e=INT_MIN;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=a[i]){
                s=min(s,i); // first element not equal starts the subarray
                e=max(e,i); // last element not equal will be end of the subarray
            }
        }
        if(s!=INT_MAX && e!=INT_MIN){
            return e-s+1;
        }
        return 0;
    }
};