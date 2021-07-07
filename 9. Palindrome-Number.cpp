//Runtime: 48 ms, faster than 91.08% of C++ online submissions for Palindrome Number.
//Memory Usage: 8.2 MB, less than 99.22% of C++ online submissions for Palindrome Number.

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int N = s.size();
        for(int i = 0; i < N; i++){
            if(s[i] != s[N-1-i]) return false;
        }
        return true;
    }
};
