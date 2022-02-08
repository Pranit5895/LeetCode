class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, -1, 0, 1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        
        queue<vector<int>> q;
        map<vector<int>, int> depth;
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(grid[r][c] == 2){
                    q.push(vector<int> {r,c});
                    depth[vector<int> {r,c}] = 0;
                }
            }
        }
        
        int ans = 0;
        while(!q.empty()){
            vector<int> rc = q.front();
            q.pop();
            int r = rc[0], c = rc[1];
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == 1){
                    //visit(modify grid) and then push into queue
                    grid[nr][nc] = 2;
                    q.push(vector<int> {nr, nc});
                    ans = depth[vector<int> {nr,nc}] =  depth[vector<int> {r,c}] + 1;
                }
            }
        }
        
        for(vector<int> row : grid){
            for(int e : row){
                if(e == 1) return -1;
            }
        }
        
        return ans;
    }
};