/*
Split a String Into the Max Number of Unique Substrings
https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

Approach - Recursion TC-> O(2^n)

*/
class Solution {
public:
    int solve(int idx,string st,string &s,set<string>&m){
        if(idx>=s.size()){
            return 0;
        }
        int ans=0;
        // add partition
        st+=s[idx];
        if(m.count(st)==0){
            m.insert(st);
            ans=max(ans,1+solve(idx+1,"",s,m));
            m.erase(st);
        }
        // don't add partition
        ans=max(ans,solve(idx+1,st,s,m));
        st.pop_back();

        return ans;
    }
    int maxUniqueSplit(string s) {
        int n=s.size();
        set<string>m;
        return solve(0,"",s,m);
    }
};