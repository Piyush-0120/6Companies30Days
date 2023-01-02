// Problem 5: Course Schedule
// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    // topological sort
    bool canFinish(int numCourses, vector<vector<int>>& p) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        
        for(auto& it:p){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        //bfs
        queue<int>q;
        // insert all independent nodes (nodes with 0-indegree, because this should be completed first)
        for(int i=0;i<n;i++){
            if(!indegree[i])
                q.push(i);
        }
        int c=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            c++; // no of courses it visited
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]) // all prerequisites are covered for this course
                    q.push(it);
            }
        }
        return c==n; // return true if all courses are visited
    }
};