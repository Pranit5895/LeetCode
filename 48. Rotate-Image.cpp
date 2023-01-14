#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                std::swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
