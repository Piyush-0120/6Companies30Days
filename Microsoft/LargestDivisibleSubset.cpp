class Solution {
public:
    // realizing it to be a dp problem, similar to LIS
    
    vector<int> largestDivisibleSubset(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>dp(n); // dp[i] -> largest subset found till ith position
        dp[0]={0}; // storing index instead of the number
        
        for(int i=1;i<n;i++){
            int sz=0;
            vector<int>v;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    if(dp[j].size()>sz){
                        sz=dp[j].size();
                        v=dp[j];
                    }
                }
            }
            v.push_back(i);
            dp[i]=v;
        }
        int sz=0,pos=-1;
        // finding max length subset over the dp vector
        for(int i=0;i<n;i++){
            if(dp[i].size()>sz){
                sz=dp[i].size();
                pos=i;
            }
        }
        
        vector<int>ans;
        for(auto it:dp[pos])
            ans.push_back(a[it]);
        
        return ans;
    }
};