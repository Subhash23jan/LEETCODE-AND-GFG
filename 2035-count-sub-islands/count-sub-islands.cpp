class Solution {
    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &flag)
    {
        int n=grid1.size(),m=grid1[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid2[i][j]==0) return;
        if(grid2[i][j]==1 && grid1[i][j]==0)
        {
            flag=false;
        }
        grid2[i][j]=0;
        dfs(i+1,j,grid1,grid2,flag);
        dfs(i,j+1,grid1,grid2,flag);
        dfs(i-1,j,grid1,grid2,flag);
        dfs(i,j-1,grid1,grid2,flag);
        
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                bool flag=true;
                if(grid2[i][j]==1){
                    dfs(i,j,grid1,grid2,flag);
                    ans+=(flag);
                }
            }
        }
        return ans;
    }
};