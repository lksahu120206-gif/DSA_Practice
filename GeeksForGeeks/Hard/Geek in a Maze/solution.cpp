class Solution {
  public:
      int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {

          int n = mat.size();
          int m = mat[0].size();

          if (mat[r][c] == '#')
              return 0;

          const int INF = 1e9;

          // dist[x][y] = minimum number of upward moves
          // required to reach (x, y)
          vector<vector<int>> dist(n, vector<int>(m, INF));

          deque<pair<int, int>> dq;

          int dx[] = {-1, 1, 0, 0};
          int dy[] = {0, 0, -1, 1};

          dist[r][c] = 0;
          dq.push_front({r, c});

          while (!dq.empty()) {

              auto [x, y] = dq.front();
              dq.pop_front();

              for (int k = 0; k < 4; k++) {

                  int nx = x + dx[k];
                  int ny = y + dy[k];

                  if (nx < 0 || nx >= n ||
                      ny < 0 || ny >= m ||
                      mat[nx][ny] == '#')
                      continue;

                  // Only an upward move consumes upward budget
                  int cost = (nx < x) ? 1 : 0;

                  if (dist[x][y] + cost < dist[nx][ny]) {

                      dist[nx][ny] = dist[x][y] + cost;

                      if (cost == 0)
                          dq.push_front({nx, ny});
                      else
                          dq.push_back({nx, ny});
                  }
              }
          }

          int ans = 0;

          for (int x = 0; x < n; x++) {
              for (int y = 0; y < m; y++) {

                  if (dist[x][y] == INF)
                      continue;

                  int up = dist[x][y];

                  // x = r - up + down
                  int down = up + x - r;

                  if (up <= u && down <= d)
                      ans++;
              }
          }

          return ans;
      }
  };