class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        int i=0,j=cols-1;
        while(j>=0 and i<rows){
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]>target)j--;
            else i++;
        }
        
        return false;
    }
};