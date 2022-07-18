class Solution {
public:
    int subarraySum(vector<int>& arr, int target){
        int res = 0, sum = 0;
        map<int, int> counter;
        counter[0] = 1;
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            if(counter.find(sum - target) != counter.end()){
                res += counter[sum - target];
            }
            counter[sum]++;
        }
        return res;
    };
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        vector<int> row(n);
        
        for(int row_low = 0; row_low < m; row_low++){
            //cumulative sum start from row_low
            fill(row.begin(), row.end(), 0);
            for(int row_high = row_low; row_high < m; row_high++){
                //cumulative sum until row_high
                for(int col = 0; col < n; col++){
                    row[col] += matrix[row_high][col];
                }
                //think the submatrix as an array
                //and then find its subarray's sum
                ans += subarraySum(row, target);
            }
        }
        
        return ans;
    }
};
