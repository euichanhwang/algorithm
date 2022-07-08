#include <bits/stdc++.h>

using namespace std;
typedef long long ll;  //-2^63 ~ 2^63-1
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<int, char> pic;
int INF = 1e9 + 7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m,k; //n은 행, m은 열, k는 부술 수 있는 벽의 개수
string board[1002];
int dist[1002][1002][12][2];
/**
 * (nx,ny)가 빈 곳 -> 이동
 * (nx,ny)가 벽 -> k개의 벽을 다 부순 경우에는 더 깰 수 없다.
 *             -> 낮이라면 깨고 넘어간다.
 *             -> 밤이라면 낮이 올때까지 기다린다.
 *  낮 : 0, 밤 : 1
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++) cin >> board[i];
    queue<tuple<int,int,int,int>> q; // x,y,부순 벽의 개수, 낮/밤.
    dist[0][0][0][0] = 1;
    q.push({0,0,0,0});
    while(!q.empty()) {
        auto[x, y, w, t] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1) {
            cout << dist[x][y][w][t];
            return 0;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '0') { // 이동할 수 있는 곳 -> 이동
                int nw = w;
                int nt = 1 - t; // 이동했으므로 낮과 밤이 바뀜
                if (dist[nx][ny][nw][nt] > 0) continue;
                dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                q.push({nx, ny, nw, nt});
            }
            else { // 벽
                if (w == k) continue; // k개의 벽을 모두 부숨
                // 낮이라면 깨고 넘어간다
                if (t == 0) {
                    int nw = w + 1;
                    int nt = 1 - t; // 이동했으므로 낮과 밤이 바뀜
                    if (dist[nx][ny][nw][nt] > 0) continue;
                    dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                    q.push({nx, ny, nw, nt});
                } else { // 밤이라면 낮이 올때까지 기다린다
                    int nt = 1 - t; // 밤 -> 낮
                    if (dist[x][y][w][nt] > 0) continue;
                    dist[x][y][w][nt] = dist[x][y][w][t] + 1;
                    q.push({x, y, w, nt});
                }
            }
        }
    }

    cout << -1;
    return 0;
}