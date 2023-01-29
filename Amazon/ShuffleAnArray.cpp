/*
https://leetcode.com/problems/shuffle-an-array/
TC-> O(n^2) [random shuffle works in O(n)]

*/
class Solution {
public:
    vector<int>original,arr;
    
    Solution(vector<int>& nums) {
        original=nums;
        arr=nums;
    }
    
    vector<int> reset() {
        arr=original;
        return arr;
    }
    
    vector<int> shuffle() {
        random_shuffle(arr.begin(), arr.end());
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */