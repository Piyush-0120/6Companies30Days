/*

Problem 15: Minimum Deletions to Make Array Divisible
https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

*/
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        int g=numsDivide[0];
        for(auto& it:numsDivide){
            g=__gcd(g,it);
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto& it:nums){
            pq.push(it);
        }
        int ans=0;
        // checking if the minimum divides all numbers in nums array
        while(!pq.empty() && g%pq.top()!=0){
            pq.pop();
            ans++;
        }
        return ans==n?-1:ans;
    }
};