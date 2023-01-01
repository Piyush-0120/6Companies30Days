// Problem 3 : Bulls and Cows
class Solution {
public:
    string getHint(string s, string g) {
        int a=0,b=0;
        // hashmap to store the frequency of digits
        vector<int>h1(10,0),h2(11,0);
        for(int i=0;i<s.size();i++){
            if(s[i]==g[i])
                a++;
            else{
                h1[s[i]-'0']++;
                h2[g[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            if(h1[i] && h2[i])
                b+=min(h1[i],h2[i]);
        }
        string ans=to_string(a)+"A"+to_string(b)+"B";
        return ans;
    }
};