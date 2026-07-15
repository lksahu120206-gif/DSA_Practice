class Solution {
public:

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    void dfs(vector<vector<int>>& image,int x,int y,int oldColor,int newColor){

        int m=image.size();
        int n=image[0].size();

        image[x][y]=newColor;

        for(int k=0;k<4;k++){

            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx>=0 && ny>=0 && nx<m && ny<n &&
               image[nx][ny]==oldColor){

                dfs(image,nx,ny,oldColor,newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int old=image[sr][sc];

        if(old==color)
            return image;

        dfs(image,sr,sc,old,color);

        return image;
    }
};