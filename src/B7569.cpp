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
int dz[6]={0,0,1,0,0,-1};
int dx[6]={0,1,0,0,-1,0};
int dy[6]={-1,0,0,1,0,0};
int m,n,h;//n이 행, m은 열, h는 높이
int board[103][103][103]; //board[i][j][k] , i가 높이,
int dist[103][103][103];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n >> h;
    queue<tuple<int,int,int>> q;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> board[i][j][k];
                if(board[i][j][k]==1) q.push({i,j,k});
                if(board[i][j][k]==0) dist[i][j][k] = -1; //좌표 값이 0 -> 토마토가 없거나 익은 토마토인 경우
            }
        }
    }
    while(!q.empty()){
        int x,y,z; // 높이, 행, 열 순서 !
        tie(x,y,z) = q.front(); q.pop();
        for(int dir=0;dir<6;dir++){
            int nz = x + dz[dir];
            int nx = y + dx[dir];
            int ny = z + dy[dir];
            if(nz<0||nx<0||ny<0||nz>=h||nx>=n||ny>=m) continue;
            if(dist[nz][nx][ny]>=0) continue;
            dist[nz][nx][ny] = dist[x][y][z] + 1;
            q.push({nz,nx,ny});
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(dist[i][j][k]==-1){
                    cout << -1;
                    return 0;
                }
                ans = max(ans,dist[i][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}