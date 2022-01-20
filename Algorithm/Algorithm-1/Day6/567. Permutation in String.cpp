class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Count(26, 0), windowCount(26, 0);
        
        for(char c : s1){
            s1Count[c-'a'] += 1;
        }
        
        for(int i = 0; i < s2.size(); i++){
            if(i < s1.size()){
                windowCount[s2[i]-'a'] += 1;
            }else{
                windowCount[s2[i]-'a'] += 1;
                windowCount[s2[i-s1.size()]-'a'] -= 1;
            }
            
            if(s1Count == windowCount){
                return true;
            }
        }
        
        return false;
    }
};