/*

Problem 11 : Number of ways to arrive at a Destination
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

Using dijkstra algorithm to find the shortest path and then calculate the ways to visit the dest node
*/
class Solution {
public:
    typedef long long ll;
    const ll mod= 1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<ll>dist(n,LONG_MAX),path(n,0);
        
        int src = 0;
        
        set<pair<ll,ll>>s; // dist,node
        dist[0]=0;
        path[0]=1;
        s.insert({0,0});
        
        while(!s.empty()){
            // find shortest pair
            ll d = s.begin()->first;
            int node = s.begin()->second;
            
            //erase this node because dist is finalized
            s.erase(s.begin());
            
            // relax the nbrs
            for(auto& it: adj[node]){
                if(d+it.second < dist[it.first]){
                    if(dist[it.first]!=1e9)
                        s.erase({dist[it.first],it.first});
                    //update path
                    path[it.first]=path[node];
                    //relax
                    dist[it.first]=d+it.second;
                    
                    // insert new pair
                    s.insert({dist[it.first],it.first});
                }
                else if(d+it.second == dist[it.first]){
                    // Node is already visited with the shortes path,update path with sum of parent and the current node path

                    path[it.first]=(0ll + path[it.first]+ path[node])%mod;
                }
            }
        }
        return path[n-1];
    }
};