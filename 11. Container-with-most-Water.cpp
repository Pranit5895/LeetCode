//WA
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int left = 0, right = N-1;
        int ans = 0;
        bool leftTurn = true;
        
        while(left < right){
            int lh = height[left], rh = height[right];
            // cout << left << " " << right << endl;
            ans = max(ans, min(lh, rh) * (right-left));
            
            if(leftTurn){
                //move left so heigh[left] is larger than old lh
                do{
                    left++;
                    // cout << "left: " << left << endl;
                }while(left < N && height[left] <= lh);
            }else{
                //move right so height[right] is larger than old rh
                do{
                    right--;
                    // cout << "right: " << right << endl;
                }while(right >= 0 && height[right] <= rh);
            }
            
            leftTurn = !leftTurn;
            
        }
        
        return ans;
    }
};

//Approach 1: Brute Force
//TLE
//time: O(n^2), space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int ans = 0;
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){
                ans = max(ans, min(height[i], height[j]) * (j-i));
            }
        }
            
        return ans;
    }
};

//Approach 2: Two Pointer Approach
//Runtime: 16 ms, faster than 96.00% of C++ online submissions for Container With Most Water.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Container With Most Water.
//time: O(n), space: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int left = 0, right = N-1, ans = 0;
        while(left < right){
            ans = max(ans, min(height[left], height[right]) * (right-left));
            //move the pointer pointing to lower bar forward,
            //because if we move the pointer pointing to higher bar forward, 
            //the area can only be shrinked
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};