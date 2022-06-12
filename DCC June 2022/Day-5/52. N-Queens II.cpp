class Solution {
public:
    bool placevalid(int row,int col,int n,int **table){
        // check horizontal
        for(int i=0;i<n;i++){
            if(table[row][i]==1){
                return false;
            }
        }
        // check vertical
        for(int i=0;i<n;i++){
            if(table[i][col]==1){
                return false;
            }
        }
        // check diagonal left
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(table[i][j]==1){
                return false;
            }
        }
        // check diagonal right
        for(int i=row,j=col;i>=0&&j<n;j++,i--){
            if(table[i][j]==1){
                return false;
            }
        }
        return true;
    }
    void nqueen(int n,int row,int &ans,int **table){
        // base case
        if(row>=n){
            ans++;
            return;
        }
        // try to fill each column of the current row
        for(int i=0;i<n;i++){
            if(placevalid(row,i,n,table)){
                // fill
                table[row][i]=1;
                // call
                nqueen(n,row+1,ans,table);
                // revert
                table[row][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int **table=new int*[n+1];
        for(int i=0;i<=n;i++){
            table[i]=new int[n+1]{};
        }
        int ans=0;
        nqueen(n,0,ans,table);
        return ans;
    }
};
