class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || visited[i][j]){
            return;
        }

        visited[i][j] = true;

        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);

        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    int isLandCount(vector<vector<int>>& grid){
        int count = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0; i<grid.size();i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                    dfs(grid,visited,i,j);
                }
            }
        }

        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        if(isLandCount(grid)!=1) return 0;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;

                    if(isLandCount(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};