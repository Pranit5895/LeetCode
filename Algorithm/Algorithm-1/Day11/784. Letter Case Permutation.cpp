class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        ans.push_back(S);
        
        for(int i = 0; i < S.size(); i++){
            char c = S[i];
            if(isalpha(c)){
                vector<string> tmpv;
                for(string prevS : ans){
                    string tmp(prevS.begin(), prevS.end());
                    if(islower(c)){
                        tmp[i] = toupper(c);
                    }else if(isupper(c)){
                        tmp[i] = tolower(c);
                    }
                    tmpv.push_back(tmp);
                }
                //concatenate
                ans.insert(ans.end(), tmpv.begin(), tmpv.end());
            }
        }
        
        return ans;
    }
};