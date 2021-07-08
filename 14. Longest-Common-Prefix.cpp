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

//Divide and Conquer
//In the worst case we have nn equal strings with length m
//Time complexity : O(S), where S is the number of all characters in the array, 
//S=m⋅n Time complexity is 2⋅T(n/2)+O(m). Therefore time complexity is O(S). 
//In the best case this algorithm performs O(minLen⋅n) comparisons, where minLen is the shortest string of the array.
//Space complexity : O(m⋅logn)
//There is a memory overhead since we store recursive calls in the execution stack. 
//There are logn recursive calls, each store need m space to store the result, so space complexity is O(m⋅logn)
//Runtime: 8 ms, faster than 98.47% of C++ online submissions for Longest Common Prefix.
//Memory Usage: 12 MB, less than 11.34% of C++ online submissions for Longest Common Prefix.

class Solution {
public:
    string commonPrefix(string left, string right){
        int _min = min(left.size(), right.size());
        for(int i = 0; i < _min; i++){
            if(left[i] != right[i]){
                //i is the length of the resulting substring
                return left.substr(0, i);
            }
        }
        return left.substr(0, _min);
    }
    string longestCommonPrefix(vector<string>& strs, int l, int r){
        if(l == r) return strs[l];
        int mid = (l+r)/2;
        string lcpL = longestCommonPrefix(strs, l, mid);
        string lcpR = longestCommonPrefix(strs, mid+1, r);
        return commonPrefix(lcpL, lcpR);
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        return longestCommonPrefix(strs, 0, strs.size()-1);
    }
};