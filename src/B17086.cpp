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
int INF=1e9+7;
//512MB = 1.2억개 int
//if(nx<0||nx>=n||ny<0||ny>=m) continue;
/*int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,1,-1};*/ // 3차원 bfs용
#define X first
#define Y second
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
//0은 빈 칸, 1은 아기 상어가 있는 칸이다.
int n,m;
int board[52][52];
int dist[52][52];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    queue<pii> q;
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==1){ //아기 상어가 있는 칸
                q.push({i,j});
                dist[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        auto cur=q.front();q.pop();
        for(int dir=0;dir<8;dir++){
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(dist[nx][ny]>=0)continue;
            dist[nx][ny]=dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }
    int max=-0x7f7f7f7f;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j]>=max)
                max=dist[i][j];
        }
     
    }
    cout << max;


    return 0;
}