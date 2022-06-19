class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        unordered_map<string, int> length;
        int ans = 1;
        
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        
        for(string& word : words){
            for(int i = 0; i < word.size(); i++){
                length[word] = max(length[word], length[word.substr(0, i)+word.substr(i+1)]+1);
            }
            ans = max(ans, length[word]);
        }
        
        return ans;
    }
};
