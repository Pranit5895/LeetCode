class Solution {
public:
    void swap(int& a, int& b){
        int temp = a;
        a = b;
        b = temp;
    }
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        if(row == 0)
            return vector<vector<int>>{};
        
        int col = A[0].size();        
        vector<vector<int>> result;
        result.resize(col, vector<int>(row));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                result[j][i] = A[i][j];
            }
        }
        
        return result;
    }
};
