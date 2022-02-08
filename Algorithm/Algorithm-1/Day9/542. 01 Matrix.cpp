class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        vector<int> index_i(m * n, -1);
        vector<int> index_j(m * n, -1);
        int beg = 0;
        int last = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    index_i[last] = i;
                    index_j[last] = j;
                    last++;
                }
            }
        }
        last = last % (m * n);
        while(beg != last) {
            int cur_i = index_i[beg];
            int cur_j = index_j[beg];
            bool flag = false;
            if ((cur_i > 0) && (res[cur_i-1][cur_j] == -1)) {
                res[cur_i-1][cur_j] = res[cur_i][cur_j] + 1;
                index_i[last] = cur_i - 1;
                index_j[last] = cur_j;
                last = (last + 1) % (m * n);
            }
            if ((cur_i < m - 1) && (res[cur_i+1][cur_j] == -1)) {
                res[cur_i+1][cur_j] = res[cur_i][cur_j] + 1;
                index_i[last] = cur_i + 1;
                index_j[last] = cur_j;
                last = (last + 1) % (m * n);
            }
            if ((cur_j > 0) && (res[cur_i][cur_j-1] == -1)) {
                res[cur_i][cur_j-1] = res[cur_i][cur_j] + 1;
                index_i[last] = cur_i;
                index_j[last] = cur_j - 1;
                last = (last + 1) % (m * n);
            }
            if ((cur_j < n - 1) && (res[cur_i][cur_j+1] == -1)) {
                res[cur_i][cur_j+1] = res[cur_i][cur_j] + 1;
                index_i[last] = cur_i;
                index_j[last] = cur_j + 1;
                last = (last + 1) % (m * n);
            }
            beg = (beg + 1) % (m * n);
        }
        return res;
    }
};