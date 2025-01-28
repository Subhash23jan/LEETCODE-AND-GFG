class Solution {
    int getFishes(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
            if(r==grid.size() || c==grid[0].size() || r<0 || c<0)
                    return 0;
            if(vis[r][c]==1 || grid[r][c]==0)
                    return 0;
            vis[r][c]=1;
            int ans=grid[r][c];
            ans+=getFishes(r+1,c,grid,vis);
            ans+=getFishes(r-1,c,grid,vis);
            ans+=getFishes(r,c+1,grid,vis);
            ans+=getFishes(r,c-1,grid,vis);
            return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++)
        {
                for(int j=0;j<grid[i].size();j++)
                {
                        if(grid[i][j]>0 && !vis[i][j])
                        {
                                ans=max(ans,getFishes(i,j,grid,vis));
                        }
                }
        }
            return ans;
    }
};