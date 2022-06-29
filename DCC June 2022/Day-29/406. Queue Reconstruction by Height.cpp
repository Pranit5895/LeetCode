class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int N = people.size();
        if(N == 0) return vector<vector<int>>();
        vector<vector<int>> ans;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){return (a[0] == b[0]) ? (a[1] < b[1]) : a[0] > b[0];});
        
        int maxh = people[0][0];
        
        
        for(int i = 0; i < N; i++){
            if(people[i][0] == maxh){
                ans.push_back(people[i]);
            }else{
                ans.insert(ans.begin()+people[i][1], people[i]);
            }
        }
        
        return ans;
    }
};
