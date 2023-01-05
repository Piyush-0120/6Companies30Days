/*

Problem 15: Number of substrings containing all three characters
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

*/
class Solution {
public:
    // sliding window
    int numberOfSubstrings(string s) {
        int n=s.size();
        int ans=0;
        int left=0,right=0;
        int m[3];
        m[0]=m[1]=m[2]=0;
        
        while(left<n){
            
            while(left<=right && right<n && !(m[0]>=1 && m[1]>=1 && m[2]>=1)){
                m[s[right]-'a']++;
                right++;
                
            }
            if(m[0]>=1 && m[1]>=1 && m[2]>=1){
                ans+=n-(right-1); // this range along with the elements in the right are also valid substrings
            }
            
            m[s[left]-'a']--;
            left++;
        }
        return ans;
        
    }
};