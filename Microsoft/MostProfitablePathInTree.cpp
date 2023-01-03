class Solution {
public:
    // calculating distance taken by bob and alice, if bob's distance = alice's dist then intersection
    // if bob's distance < alice's dist then bob already travelled through this node
    // if bob's distance < alice's dist then alice will travell this node first
    
    bool dfs(int node,int d,vector<int>&vis,vector<int>&dis,vector<vector<int>>&adj){
        vis[node]=1;
        dis[node]=d;
        // base case -> when node 0 is reached
        if(node==0)
            return true;
        
        for(auto& it: adj[node]){
            if(vis[it]==0){
                if(dfs(it,d+1,vis,dis,adj))
                    return true;
            }
        }
        dis[node]=-1; // key step, nodes which are not part of the path are assigned -1
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        int ans=INT_MIN;
        vector<vector<int>>adj(n);
        for(auto& it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>dis(n,-1),vis(n,0);
        //resolve bob first
        dfs(bob,0,vis,dis,adj);

        fill(vis.begin(),vis.end(),0); // reassign visited vector
        // bfs
        queue<pair<int,pair<int,int>>>q; //node,{distance,income}
        q.push({0,{0,amount[0]}});
        vis[0]=1;
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second.first;
            int income = q.front().second.second;
            q.pop();
            
            
            // leaf node reached
            if(adj[node].size()==1 && node!=0){
                ans=max(ans,income);
            }
            
            for(auto& it: adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    int net_income=income;
                    if(dis[it]!=-1){
                        if(distance+1<dis[it])
                            net_income+=amount[it];
                        else if(distance+1 == dis[it]) // point of intersection
                            net_income+=(amount[it]/2);
                    }
                    else
                        net_income+=amount[it];
                    q.push({it,{distance+1,net_income}});
                }
            }   
        }
        return ans;
    }
};