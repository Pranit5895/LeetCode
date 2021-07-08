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

//Vertical scanning
//Time complexity : O(S) , where S is the sum of all characters in all strings. 
//In the worst case there will be nn equal strings with length mm and the algorithm performs S=m⋅n character comparisons. 
//Even though the worst case is still the same as Approach 1, 
//in the best case there are at most n⋅minLen comparisons where minLen is the length of the shortest string in the array.
//Space complexity : O(1). We only used constant extra space. 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        for(int i = 0; i < strs[0].size(); i++){
            //i: index of char
            for(int j = 1; j < strs.size(); j++){
                //j: index of str
                if(i >= strs[j].size() || strs[0][i] != strs[j][i]){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};