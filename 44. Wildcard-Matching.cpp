//recursion
//TLE
//939 / 1809 test cases passed.
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0) return s.size() == 0;

        bool first_match = (s.size() > 0) && (p[0] == s[0] || p[0] == '?' || p[0] == '*');

        if(p[0] == '*'){
            return first_match && isMatch(s.substr(1), p) ||
                isMatch(s, p.substr(1));
        }else{
            //includes the case when p[0] is equal to '?'
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};