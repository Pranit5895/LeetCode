class Solution 
{
public:
    int maxSubarraySumCircular(vector<int>& A) 
    {
        int len = A.size();
        int ans1 = A[0]; 
        int ans2 = A[0];
        int curr = A[0];
       
        for(int i=1;i<len;i++)
        {
            curr = max(A[i],curr+A[i]);
            ans1 = max(ans1,curr);
        }
        curr = -1*A[0];
        ans2 = -1*A[0];
        int sum = accumulate(A.begin(),A.end(),0);
        for(int i=1;i<len;i++)
        {
            int val = (-1*A[i]);
            curr = max(val,curr+val);
            ans2 = max(ans2,curr);
        }
        if (sum+ans2==0)
            return ans1;
        return max(ans1,ans2+sum);
    }
};
