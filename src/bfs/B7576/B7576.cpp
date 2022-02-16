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
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs용
#define X first
#define Y second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[1002][1002];
int dist[1002][1002];
int m,n;
//정수 1은 익은 토마토, 정수 0은 익지않은 토마토, -1은 토마토가 없다.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    queue<pii> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1)// 익은 토마토인경우
            {
                dist[i][j]=0;
                q.push({i,j}); //여기서부터 시작한다.

            }
            if(board[i][j]==0)// 익지않은 토마토인경우
            {
                dist[i][j]=-1;
            }
        }
    }
    //익은 토마토와 토마토가 없을 때 는 0, 익지 않은 토마토일때는 -1이 들어간다.
    while(!q.empty())
    {
        auto cur=q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0)continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(dist[i][j]==-1) //bfs를 다 돌았는데 익지 않은 토마토가 있다면
            {
                cout << -1;
                return 0;
            }
            ans=max(ans,dist[i][j]);
        }
    }
    cout << ans;


}