class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    
     int i=0,n=nums.size(),j=0,sum=0,c=0,t_sum=0;
        for(i=0;i<n;i++)
        {
            t_sum+=nums[i];
            
        } 
        int req = t_sum-x;
        if(req == 0)
            return n;
        unordered_map<int,int> sum_map;
        sum_map[0]=-1;
        sum_map[nums[0]]=0;
        if(nums[0]==req) c=1;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum_map.find(sum)==sum_map.end())
                sum_map[sum] = i;
            if(sum_map.find(sum-req) !=sum_map.end())
                c = max(c,i-sum_map[sum-req]);
            
        }
        if(c==0)
            return -1;
        return n-c;
    }
};
