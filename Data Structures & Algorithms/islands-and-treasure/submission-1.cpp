class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()){
            return;
        }
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        const int dr[]={-1,1,0,0};
        const int dc[]={0,0,-1,1};
        const int INF=2147483647;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
    // Boundary checks and check if it's an unvisited empty land (INF)
                if (nr>=0 && nr<n && nc >= 0 && nc < m && grid[nr][nc] == INF) {
                    grid[nr][nc] = grid[r][c] + 1; // Update shortest distance
                    q.push({nr, nc});
                }
            }
        }

    }
};
