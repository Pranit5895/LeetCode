//Horizontal scanning
//time: O(S), where S is the sum of all characters in all strings.
//space: O(1)
//Runtime: 8 ms, faster than 98.47% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 9 MB, less than 98.54% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int ans = INT_MAX;
        for(int i = 0; i < strs.size()-1; i++){
            ans = min(ans, (int)min(strs[i].size(), strs[i+1].size()));
            while(strs[i].substr(0, ans) != strs[i+1].substr(0, ans)){
                ans--;
            }
            if(ans == 0)return "";
        }
        return strs[0].substr(0, ans);
    }
};