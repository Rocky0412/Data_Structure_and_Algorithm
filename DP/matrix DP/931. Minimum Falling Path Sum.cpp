/*

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int op1= j-1 < 0 ? INT_MAX :matrix[i+1][j-1];
                int op2= matrix[i+1][j];
                int op3= j+1>=m ? INT_MAX : matrix[i+1][j+1];
                matrix[i][j]=matrix[i][j] + min({op1,op2,op3});
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,matrix[0][i]);
        }
        return ans;
    }
};