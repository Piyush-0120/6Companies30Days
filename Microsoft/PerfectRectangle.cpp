/*
Problem 5: Perfect Rectangle
https://leetcode.com/problems/perfect-rectangle/

The right answer must satisfy two conditions:-
1.the large rectangle area should be equal to the sum of small rectangles
2.count of all the points should be even, and that of all the four corner points should be one


*/

class Solution {
public:
    typedef long long ll;
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int x1,x2,y1,y2;
        x1=y1=INT_MAX;
        x2=y2=INT_MIN;
        set<pair<int,int>>s;
        ll area=0ll;
        for(auto& it:rectangles){
            x1=min(x1,it[0]);
            x2=max(x2,it[2]);
            y1=min(y1,it[1]);
            y2=max(y2,it[3]);
            
            // (x2-x1)*(y2-y1)
            area+=1ll*(it[2]-it[0])*(it[3]-it[1]);

            if(s.count({it[0],it[1]}))
                s.erase(s.find({it[0],it[1]}));
            else
                s.insert({it[0],it[1]});
            
            if(s.count({it[0],it[3]}))
                s.erase(s.find({it[0],it[3]}));
            else
                s.insert({it[0],it[3]});
            
            if(s.count({it[2],it[1]}))
                s.erase(s.find({it[2],it[1]}));
            else
                s.insert({it[2],it[1]});
            
            if(s.count({it[2],it[3]}))
                s.erase(s.find({it[2],it[3]}));
            else
                s.insert({it[2],it[3]});
        }
        
        ll biggerArea = 1ll*(x2-x1)*(y2-y1);
        if(s.size()==4 && s.count({x1,y1}) && s.count({x1,y2}) && s.count({x2,y1}) &&s.count({x2,y2}) && biggerArea==area)
            return true;
        return false;
    }
};