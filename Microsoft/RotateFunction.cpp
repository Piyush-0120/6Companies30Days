// Problem 3: https://leetcode.com/problems/rotate-function/ 
class Solution {
public:
    // using sliding window techinque [window size=n]
    // here the window in circular
    int maxRotateFunction(vector<int>& a) {
        int n=a.size();
        int ans=INT_MIN;
        int sum=0;
        int pre[n];
        for(int i=0;i<n;i++){
            pre[i]=(i-1>=0?pre[i-1]:0)+a[i]; // to find sum of a range in O(1)
            sum+=i*a[i];
        }
        ans=max(ans,sum);
        for(int i=1;i<n;i++){
            int left=0;
            if(i-2>=0){
                left=pre[i-2];
            }
            int right=pre[n-1]-pre[i-1];
            sum+=(n-1)*a[i-1]-(left+right); // a[i-1] becomes the last element of the window
            ans=max(ans,sum);
        }
        
        return ans;
    }
};