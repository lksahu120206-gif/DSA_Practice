class Solution {
  public:

      int shortestPath(vector<vector<int>>& mat) {

          int n = mat.size();
          int m = mat[0].size();

          int dx[] = {-1, 1, 0, 0};
          int dy[] = {0, 0, -1, 1};

          vector<vector<bool>> safe(n, vector<bool>(m, true));

          for(int i = 0; i < n; i++) {
              for(int j = 0; j < m; j++) {

                  if(mat[i][j] == 0) {

                      safe[i][j] = false;

                      for(int k = 0; k < 4; k++) {

                          int ni = i + dx[k];
                          int nj = j + dy[k];

                          if(ni >= 0 && ni < n &&
                             nj >= 0 && nj < m) {

                              safe[ni][nj] = false;
                          }
                      }
                  }
              }
          }

          queue<pair<int,int>> q;

          vector<vector<int>> dist(
              n, vector<int>(m, -1)
          );

          for(int i = 0; i < n; i++) {

              if(safe[i][0]) {

                  q.push({i, 0});
                  dist[i][0] = 1;
              }
          }

          while(!q.empty()) {

              auto [x, y] = q.front();
              q.pop();

              if(y == m - 1)
                  return dist[x][y];

              for(int k = 0; k < 4; k++) {

                  int nx = x + dx[k];
                  int ny = y + dy[k];

                  if(nx < 0 || nx >= n ||
                     ny < 0 || ny >= m)
                      continue;

                  if(!safe[nx][ny])
                      continue;

                  if(dist[nx][ny] != -1)
                      continue;

                  dist[nx][ny] = dist[x][y] + 1;

                  q.push({nx, ny});
              }
          }

          return -1;
      }
  };