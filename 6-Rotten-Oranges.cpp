#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        //this data structure will store all the initial starting points along with the time
        queue<pair<pair<int,int>,int>>q;

        //visited array
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){

                    //this is to determine all the starting points
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        }

        int delrow[]={-1,0,+1,0}; //delta row to visit 4 directionally
        int delcol[]={0,+1,0,-1}; //delta col to visit 4 directionally
        int time=0;

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(time,t);

            for(int i=0;i<4;i++){
                int newRow=r+delrow[i];
                int newCol=c+delcol[i];

                if(newRow>=0 and newRow<n and newCol>=0 and newCol<m and !vis[newRow][newCol] and 
                    grid[newRow][newCol]==1){

                        vis[newRow][newCol]=2;
                        q.push({{newRow,newCol},t+1});
                }
            }        
        }


        //checking if any fresh orange is left

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 and grid[i][j]==1) return -1;
            }
        }

        return time;
    }
};