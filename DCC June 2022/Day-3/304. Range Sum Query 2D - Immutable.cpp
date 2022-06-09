class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if(matrix.empty())
            return ;
        int n = matrix[0].size();
        v = vector<vector<int>> (m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    v[i][j] = matrix[0][0];
                } else if(i == 0) {
                    v[i][j] = v[i][j-1] + matrix[i][j];
                } else if(j == 0) {
                    v[i][j] = v[i-1][j] + matrix[i][j];
                } else {
                    v[i][j] = v[i-1][j] + v[i][j-1] + matrix[i][j] - v[i-1][j-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) {
            return v[row2][col2];
        } else if(row1 == 0) {
            return v[row2][col2] - v[row2][col1-1];
        } else if(col1 == 0) {
            return v[row2][col2] - v[row1-1][col2];
        } else {
            return v[row2][col2] - v[row1-1][col2] - v[row2][col1-1] + v[row1-1][col1-1];
        }
    }
};
