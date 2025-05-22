class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>& checked,vector<vector<char>>& grid){
        if(i<grid.size() and j<grid[0].size() and i>=0 and j>=0 and !checked[i][j] and grid[i][j]=='1'){
            checked[i][j]=true;
            dfs(i+1,j,checked,grid);
            dfs(i-1,j,checked,grid);
            dfs(i,j+1,checked,grid);
            dfs(i,j-1,checked,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector checked(grid.size(),vector<bool>(grid[0].size()));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' and !checked[i][j]){
                    dfs(i,j,checked,grid);
                    count++;
                }
            }

        }
        return count;
    }
};
