//Runtime: 116 ms, faster than 8.32% of C++ online submissions for ZigZag Conversion.
//Memory Usage: 40 MB, less than 9.36% of C++ online submissions for ZigZag Conversion.
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        
        vector<vector<char>> zz(numRows, vector<char>(n, ' '));
        int r = 0, c = 0;
        //direction: false for down, true for up
        bool d = false;
        
        for(int i = 0; i < n; ++i){
            // cout << "(" << r << ", " << c << ")" << endl;
            zz[r][c] = s[i];
            if(!d){
                ++r;
            }else{
                --r;
                ++c;
            }
            
            if(r == 0 || r == numRows-1)
                d = !d;
        }
        
        string ans;
        
        for(int r = 0; r < numRows; ++r){
            for(int c = 0; c < n; ++c){
                if(zz[r][c] != ' '){
                    ans += zz[r][c];
                    if(ans.size() == n) break;
                }
            }
            if(ans.size() == n) break;
        }
        
        return ans;
    }
};

//Approach 1: Sort by Row
//Runtime: 12 ms, faster than 99.63% of C++ online submissions for ZigZag Conversion.
//Memory Usage: 11 MB, less than 24.06% of C++ online submissions for ZigZag Conversion.
//time: O(N), space: O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        int n = s.size();
        
        vector<string> rows(min(numRows,n));
        int r = 0;
        bool down = true;
        
        for(char c : s){
            rows[r] += c;
            r += down ? 1 : -1;
            if(r == 0 || r == numRows-1)
                down = !down;
        }
        
        string ans;
        for(string& row : rows){
            ans += row;
        }
        return ans;
    }
};