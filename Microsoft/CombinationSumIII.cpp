// Problem 2: Combination Sum with a twist
class Solution {
public:
    void solve(int idx,int target,int k,vector<int>&out,vector<vector<int>>&ans){
        // base case
        if(k==0){
            if(target==0){
                ans.push_back(out);
            }
        }
        
        // recursive case
        for(int i=idx;i<=9;i++){
            if(target-i>=0){
                out.push_back(i);
                solve(i+1,target-i,k-1,out,ans);
                out.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans; // to store all the possible valid combinations
        vector<int>out;
        solve(1,n,k,out,ans);
        return ans;
    }
};