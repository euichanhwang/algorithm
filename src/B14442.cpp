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
string board[1002];
int dist[1002][1002][12];
int n,m,k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    //시작 지점이 1이기 때문에 dist배열 초기화하지 않아도 된다.
    for(int i=0;i<n;i++) cin >> board[i];

    dist[0][0][0] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while(!q.empty()){
        auto [x,y,w] = q.front(); q.pop();
        if(x==n-1 && y==m-1){ //종료조건
            cout << dist[x][y][w];
            return 0;
        }
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx<0||ny<0||nx>=n||ny>=m) continue; //범위 체크
            int nw = w;
            if(board[nx][ny]=='1') nw++;
            if(nw>k || dist[nx][ny][nw]>0) continue;
            dist[nx][ny][nw] = dist[x][y][w]+1;
            q.push({nx,ny,nw});
        }
    }
    cout << -1;
    return 0;
}