class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int target
        , int row_min, int row_max, int col_min, int col_max){
        if(row_min > row_max) return false;
        if(col_min > col_max) return false;
        int row = (row_min + row_max)/2;
        int col = (col_min + col_max)/2;
        
        if(target == matrix[row][col]){
            return true;
        }else if(target > matrix[row][col]){
            return binarySearch(matrix, target, row_min, row_max, col+1, col_max) ||
                binarySearch(matrix, target, row+1, row_max, col_min, col);
        }else{
            return binarySearch(matrix, target, row_min, row_max, col_min, col-1) ||
                binarySearch(matrix, target, row_min, row-1, col, col_max);
        }
    };
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        return binarySearch(matrix, target, 0, m-1, 0, n-1);
    }
};
