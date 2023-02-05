/*
Tweet Counts per Frequency
https://leetcode.com/problems/tweet-counts-per-frequency/

*/

class TweetCounts {
public:
    map<string,vector<int>>m;
    // "tweet3": 60 , 71 , 90 
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> solve(string freq, string tweetName, int startTime, int endTime,int interval){
        vector<int>v=m[tweetName];
        sort(v.begin(),v.end());
        int i=startTime;
        vector<int>ans;
        while(i<=endTime){
            int l = i;
            i=min(i+interval-1,endTime);
            auto x1 = upper_bound(v.begin(),v.end(),i); // O(log n)
            auto x2 = lower_bound(v.begin(),v.end(),l);
            ans.push_back(x1-x2);
            i++;
        }
        return ans;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval=60;
        if(freq== "minute"){
            interval=60;
        }
        else if(freq == "hour"){
            interval=3600;
        }
        else if(freq == "day"){
            interval=86400;
        }
        return solve(freq,tweetName,startTime,endTime,interval);
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */