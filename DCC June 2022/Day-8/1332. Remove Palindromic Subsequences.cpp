class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        if(string(s.rbegin(), s.rend()) == s) return 1;
        return 2;
    }
};
