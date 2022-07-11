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
int n, m;
int board[8][8];
int boardCopy[8][8];
bool vis[8][8];
int ans; // 안전 영역의 크기
/**
 * 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳
 * 벽은 3개를 꼭 세워야 한다.
 * 안전 영역의 최댓값
 */
void copyArray(int des[8][8], int src[8][8]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            des[i][j] = src[i][j];
        }
    }
}

void spreadVirus() { // 바이러스(2) 를 전파시킴. -> 모든 빈칸으로 전파
    int spread[8][8];
    copyArray(spread, boardCopy);
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(spread[i][j]==2){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    // 바이러스 전파
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(board[nx][ny]==2||vis[nx][ny]) continue;
            if(spread[nx][ny]==0){
                spread[nx][ny] = 2;
                q.push({nx,ny});
//                vis[nx][ny] = 1;
            }
        }
    }
    // 안전 영역의 개수 구하기
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            if (spread[i][j] == 0) cnt++;
        }
    }
    ans = max(ans,cnt);
}

// 벽 두개를 세우기
void makeWall(int cur) {
    if (cur == 3) { // 벽이 3개.
        spreadVirus();
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (boardCopy[i][j] == 0) {
                boardCopy[i][j] = 1;
                makeWall(cur + 1);
                boardCopy[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) { // 빈 칸에만 벽을 세울 수 있다
                memset(vis, 0, sizeof(vis));
                copyArray(boardCopy, board);
                boardCopy[i][j] = 1;
                makeWall(1);
                boardCopy[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}