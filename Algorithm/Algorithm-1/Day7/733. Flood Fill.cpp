class Solution {
public:
    int oc;
    int nc;
    
    void dfs(vector<vector<int>>& image, int r, int c){
        if(image[r][c] == oc){
            image[r][c] = nc;
            if(r > 0) dfs(image, r-1, c);
            if(c > 0) dfs(image, r, c-1);
            if(r < image.size()-1) dfs(image, r+1, c);
            if(c < image[0].size()-1) dfs(image, r, c+1);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oc = image[sr][sc];
        nc = newColor;
        
        if(oc != nc){
            dfs(image, sr, sc);
        }
        return image;
    }
};