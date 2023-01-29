/*

https://leetcode.com/problems/cheapest-flights-within-k-stops/

Using Dijkstra's Algorithm
Time Complexity : O(E)
Space Complexity : O(E)
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        
        vector<int>c(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;//node,level,cost
        
        int ans=INT_MAX;
        c[src]=0;
        q.push({src,{0,0}});
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            for(auto it:adj[node]){
                if(cost+it.second<c[it.first] && d<k+1){
                    c[it.first]=cost+it.second;
                    q.push({it.first,{d+1,c[it.first]}});
                }
            }
        }
        
        return c[dst]==INT_MAX?-1:c[dst];
        
    }
};