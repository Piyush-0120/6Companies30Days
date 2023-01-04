/*
    Problem 10: Shortest Unsorted Continuous Subarray
    https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

*/
class Solution {
public:
    // T.C -> O(n) approach
    // in a sorted array-> a0 <= a1 <= a2 .. <= an 
    // making use of the above property to check which numbers are not in their position
    // the max till now is checked with other numbers while going from left to right
    // the min till now is checked with other numbers while going from right to left
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        int ma=a[0];
        int s=INT_MAX,e=INT_MIN;
        for(int i=1;i<n;i++){
            if(ma>a[i]){
                s=min(s,i);
                e=max(e,i);
            }
            else{
                ma=max(ma,a[i]);
            }
        }
        int mi=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(mi<a[i]){
                s=min(s,i);
                e=max(e,i);
            }
            else{
                mi=min(mi,a[i]);
            }
        }
        if(s!=INT_MAX && e!=INT_MIN)
            return e-s+1;
        return 0;
    }
};