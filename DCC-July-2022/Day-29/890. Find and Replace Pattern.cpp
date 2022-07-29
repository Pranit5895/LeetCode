class Solution {
public:
    bool match(string word,string par)
    {
        unordered_map<char,char>h1;
        unordered_map<char,char>h2;

        for(int i=0;i<word.length();i++)
        {
            if(h1.find(word[i])==h1.end())
                h1[word[i]]=par[i];

            if(h2.find(par[i])==h2.end())
                h2[par[i]]=word[i];

            
            if (h1[word[i]]!=par[i] || h2[par[i]]!=word[i])
                return false;
        }
        return true;
    }



    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {

        vector<string>ans;
        
        for(int i=0;i<words.size();i++)
        {
            if(match(words[i],pattern))
            {
                ans.push_back(words[i]);
            }
        }
        return ans;

        // pattern abbb
        // word mees aqqs

        // h1-> a-

        
    }
};
