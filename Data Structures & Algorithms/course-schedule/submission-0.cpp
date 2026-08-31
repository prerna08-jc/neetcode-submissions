class Solution {
public:
    bool iscycledfs(int src,vector<bool> &vis,vector<bool> &recPath, vector<vector<int>> & edges){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<edges.size();i++){
            int v=edges[i][0];
            int u=edges[i][1];
            if(u==src){
                if(!vis[v]){
                    if(iscycledfs(v,vis,recPath,edges)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,0);
        vector<bool> recPath(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycledfs(i,vis,recPath,edges)){
                    return false;
                }
            }
        }
        return true;
    }
};
