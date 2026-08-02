class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& visited, vector<int>& traversalpath){
        visited[node] = 1;
        traversalpath[node] = 1;

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(adj, neighbor, visited, traversalpath)){
                    return true;
                }
            }

            else if(traversalpath[neighbor]){
                return true;
            }  
        }

        traversalpath[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i = 0 ; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int> visited(numCourses, 0);
        vector<int> traversalpath(numCourses, 0);

        for(int  i = 0; i<numCourses; i++){
            if(!visited[i]){
                //dfs designed to find cycle, if cycle exists, returns false here itself, but if 
                //DAG then returns true later 
                if(dfs(adj, i, visited, traversalpath)){
                    return false;
                }
            }
        }
    return true; 

    }
};