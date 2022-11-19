class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans, vector<vector<int>>&image, 
                int  color, int delRow[], int delCol[],int n,int m,int initialColor){
        
        ans[row][col]=color;

        for(int i=0;i<4;i++){
            int nr=row+delRow[i];
            int nc=col + delCol[i];

            if(nr>=0 and nc>=0 and nr<n and nc < m and image[nr][nc]==initialColor and ans[nr][nc]!=color){
                dfs(nr,nc,ans,image,color,delRow,delCol,n,m,initialColor);
            }
        }
        

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int initialColor=image[sr][sc];
        vector<vector<int>>ans=image;
        int deltaRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        dfs(sr,sc,ans,image,color,deltaRow,delCol,n,m,initialColor);
        return ans;
    }
};